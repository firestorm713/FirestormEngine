#include"GUIMaterial.h"
GUIMaterial::GUIMaterial(std::shared_ptr<ShaderProgram> shader_program, std::shared_ptr<SDL_Surface> _texture)
	:Material(shader_program)
{
	TexCoord_Attribute = glGetAttribLocation(Program, "texcoord");
	Tex_Uniform = glGetAttribLocation(Program, "tex");
	Trans_Uniform = glGetUniformLocation(Program, "Trans");
	Texture = _texture;
	glGenTextures(1, &Tex_Object);
	glBindTexture(GL_TEXTURE_2D, Tex_Object);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Texture->w, Texture->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Texture->pixels);
	glUniform1i(Tex_Uniform, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

GUIMaterial::~GUIMaterial()
{
}

void GUIMaterial::RefreshTexture()
{
	glBindTexture(GL_TEXTURE_2D, Tex_Object);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Texture->w, Texture->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Texture->pixels);
	glUniform1i(Tex_Uniform, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}