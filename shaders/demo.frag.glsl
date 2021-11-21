#version 320 es

precision mediump float;

in vec3 FragmentNormal;
in vec3 FragmentPosition;

uniform vec3 ModelColor;
uniform vec3 LightColor;
uniform vec3 LightPosition;

out vec4 FragColor;

void main()
{
	vec3 normal = normalize(FragmentNormal);
	vec3 lightDirection = normalize(LightPosition - FragmentPosition);
	vec3 ambiant = 0.1 * LightColor;
	vec3 diffuse = max(dot(normal, lightDirection), 0.0) * LightColor;
	FragColor = vec4(ModelColor * (ambiant + diffuse), 1.0);
}
