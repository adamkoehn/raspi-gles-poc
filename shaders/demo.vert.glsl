#version 320 es

layout (location = 0) in vec3 Vertex;
layout (location = 1) in vec3 Normal;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec3 FragmentNormal;
out vec3 FragmentPosition;

void main()
{
	gl_Position = Projection * View * Model * vec4(Vertex, 1.0);
	FragmentNormal = mat3(transpose(inverse(Model))) * Normal;
	FragmentPosition = vec3(Model * vec4(Vertex, 1.0));
}
