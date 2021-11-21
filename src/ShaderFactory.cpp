#include "ShaderFactory.h"

DemoShader *ShaderFactory::makeDemoShader()
{
	ShaderBuilder *builder = new ShaderBuilder();

	unsigned int vshader = builder->compileVertexShader("shaders/demo.vert.glsl");
	unsigned int fshader = builder->compileFragmentShader("shaders/demo.frag.glsl");
	unsigned int program = builder->linkProgram(vshader, fshader);

	delete builder;

	return new DemoShader(program);
}
