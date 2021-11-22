#version 320 es

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;

uniform struct LightInfo {
	vec4 Position;
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;
} Light;

uniform struct MaterialInfo {
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;
	float Shininess;
} Material;

uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ProjectionMatrix;

out vec3 LightIntensity;

void main()
{
	vec3 n = normalize(NormalMatrix * VertexNormal);
	vec4 camCoords = ModelViewMatrix * vec4(VertexPosition, 1.0);
	vec3 ambient = Light.Ambient * Material.Ambient;
	vec3 s = normalize(vec3(Light.Position - camCoords));
	float sDotN = max(dot(s, n), 0.0);
	vec3 diffuse = Light.Diffuse * Material.Diffuse * sDotN;
	vec3 spec = vec3(0.0);
	if (sDotN > 0.0) {
		vec3 v = normalize(-camCoords.xyz);
		vec3 r = reflect(-s, n);
		spec = Light.Specular * Material.Specular
			* pow(max(dot(r, v), 0.0), Material.Shininess);
	}

	LightIntensity = ambient + diffuse + spec;
	gl_Position = ProjectionMatrix * ModelViewMatrix * vec4(VertexPosition, 1.0);
}