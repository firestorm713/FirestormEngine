#pragma once
#include "Material.h"
class GUIMaterial : public Material
{
public:
	GUIMaterial(std::shared_ptr<SDL_Surface> _texture);//std::shared_ptr<ShaderProgram> shader_program, 
	~GUIMaterial();
	GLint TexCoord_Attribute;
	GLuint Tex_Object;
	GLint Tex_Uniform;
	GLint Trans_Uniform;
	void RefreshTexture();
};