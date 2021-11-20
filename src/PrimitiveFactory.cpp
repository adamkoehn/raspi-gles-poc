#include "PrimitiveFactory.h"

Triangle *PrimitiveFactory::bufferTriangle()
{
    unsigned int vao;
	unsigned int vbo;

	float verticies[] = {
		0.0f, 0.5f, 0.0f, 0.0f, 1.0f, // top, blue
		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f, // left, red
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // right, green
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 2));
	glEnableVertexAttribArray(1);

    return new Triangle(vao);
}