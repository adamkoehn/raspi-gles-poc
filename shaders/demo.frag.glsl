#version 320 es

precision mediump float;

in vec3 VertexColor;

out vec4 FragColor;

void main()
{
	FragColor = vec4(VertexColor, 1.0);
}
