#version 320 es

layout (location = 0) in vec2 Vertex;
layout (location = 1) in vec3 Color;

out vec3 VertexColor;

void main()
{
	VertexColor = Color;
	gl_Position = vec4(Vertex, 0.0, 1.0);
}
