#include "PrimitiveFactory.h"

Cube *PrimitiveFactory::buildCube(DemoShader *shader)
{
	unsigned int vao;
	unsigned int vbo;

	float verticies[] = {
		// top face left
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // 0 - top left back
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,   // 1 - top left front
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,	   // 3 - top right front

		// top face right
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // 0 - top left back
		0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // 2 - top right back
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,	   // 3 - top right front

		// back face left
		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  // 0 - top left back
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, // 4 - bottom left back
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  // 6 - bottom right back

		// back face right
		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  // 0 - top left back
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,   // 2 - top right back
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  // 6 - bottom right back

		// bottom face left
		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, // 4 - bottom left back
		-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,  // 5 - bottom left front
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,   // 7 - bottom right front

		// bottom face right
		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, // 4 - bottom left back
		0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,  // 6 - bottom right back
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,   // 7 - bottom right front

		// front face left
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,   // 1 - top left front
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,  // 5 - bottom left front
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,   // 7 - bottom right front

		// front face right
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,   // 1 - top left front
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,	   // 3 - top right front
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,   // 7 - bottom right front

		// left face top
		-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,  // 0 - top left back
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, // 4 - bottom left back
		-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,  // 5 - bottom left front

		// left face bottom
		-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,  // 0 - top left back
		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,   // 1 - top left front
		-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,  // 5 - bottom left front

		// right face top
		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,   // 2 - top right back
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,	   // 3 - top right front
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,   // 7 - bottom right front

		// right face bottom
		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,   // 2 - top right back
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  // 6 - bottom right back
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,   // 7 - bottom right front
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void *)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);

	return new Cube(shader, vao);
}