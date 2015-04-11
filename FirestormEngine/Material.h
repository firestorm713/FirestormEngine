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
	GLuint Program;
	Material(std::shared_ptr<ShaderProgram> _program);
	GLint Position_Attribute;
	GLint TexCoord_Attribute;
	GLint Color_Uniform;
	GLint Texture_Uniform;
	GLuint Texture_Object;
	GLuint Model_Uniform;
	GLuint View_Uniform;
	GLuint Projection_Uniform;
	std::shared_ptr<ShaderProgram> Shader_Program;
	std::shared_ptr<SDL_Surface> Texture;
	void SetTexture(std::shared_ptr<SDL_Surface> _texture);
	~Material();
};