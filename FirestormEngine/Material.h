// contains pointer to a shader and all shader values
// provides interface for interacting with shader values
#pragma once
#include<GL/glew.h>

class Material
{
private:
public:
	GLuint Program;
	Material(GLuint _program);
	~Material();
};