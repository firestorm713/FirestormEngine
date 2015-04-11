#include"Material.h"
Material::Material(std::shared_ptr<ShaderProgram> _program)
{
	Shader_Program = _program;
	Program = Shader_Program->Program;
	Position_Attribute = glGetAttribLocation(Program, "position");
	TexCoord_Attribute = glGetAttribLocation(Program, "texcoord");
	Color_Uniform = glGetUniformLocation(Program, "color");
	glUniform3f(Color_Uniform, 1.0f, 1.0f, 1.0f);
	Texture_Uniform = glGetUniformLocation(Program, "tex");
	Model_Uniform = glGetUniformLocation(Program, "model");
	View_Uniform = glGetUniformLocation(Program, "view");
	Projection_Uniform = glGetUniformLocation(Program, "proj");
}

Material::~Material()
{
	glDeleteTextures(1, &Texture_Object);
}

void Material::SetTexture(std::shared_ptr<SDL_Surface> _texture)
{
	Texture = _texture;
	glGenTextures(1, &Texture_Object);
	glBindTexture(GL_TEXTURE_2D, Texture_Object);
	glActiveTexture(GL_TEXTURE0);
	int width = _texture->w;
	int height = _texture->h;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _texture->pixels);
	glUniform1i(Texture_Uniform, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}