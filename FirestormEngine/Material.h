// contains pointer to a shader and all shader values
// provides interface for interacting with shader values
#pragma once
#include<GL/glew.h>
#include<SDL_image.h>
#include<glm\glm.hpp>
#include<memory>
#include"ShaderProgram.h"
class Material
{
private:
public:
	Material(std::shared_ptr<ShaderProgram> shader_program);
	~Material();
	std::shared_ptr<ShaderProgram> Shader_Program;
	GLuint Program;
	GLint Position_Attribute;
	GLint Color_Uniform;
	std::shared_ptr<SDL_Surface> Texture;
	virtual void RefreshTexture();
};