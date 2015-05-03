#pragma once
#include "Material.h"
#include "ShaderProgram.h"

class FlatTransformed : public Material
{
public:
	FlatTransformed(std::shared_ptr<ShaderProgram> shader_program, std::shared_ptr<SDL_Surface> _texture);
	~FlatTransformed();
	GLuint Texture_Object;
	GLint Model_Uniform;
	GLint View_Uniform;
	GLint Projection_Uniform;
};