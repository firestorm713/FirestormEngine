#include"GUIMaterial.h"
GUIMaterial::GUIMaterial(std::shared_ptr<SDL_Surface> _texture)//std::shared_ptr<ShaderProgram> shader_program, 
	:Material(std::shared_ptr<ShaderProgram>(new ShaderProgram("basicTex.vertex","basicTex.fragment")))
{
	TexCoord_Attribute = glGetAttribLocation(Program, "texcoord");
	Tex_Uniform = glGetAttribLocation(Program, "tex");
	Trans_Uniform = glGetUniformLocation(Program, "Trans");
	Texture = _texture;
	glGenTextures(1, &Tex_Object);
	glBindTexture(GL_TEXTURE_2D, Tex_Object);
	int mode = GL_RGB;
	if (_texture->format->BytesPerPixel == 4)
		mode = GL_RGBA;
	glTexImage2D(GL_TEXTURE_2D, 0, mode, Texture->w, Texture->h, 0, mode, GL_UNSIGNED_BYTE, Texture->pixels);

	std::cout << (int)_texture->format->BitsPerPixel << std::endl;

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
	int mode = GL_RGB;
	if (Texture->format->BytesPerPixel == 4)
		mode = GL_RGBA;
	glTexImage2D(GL_TEXTURE_2D, 0, mode, Texture->w, Texture->h, 0, mode, GL_UNSIGNED_BYTE, Texture->pixels);
	glUniform1i(Tex_Uniform, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}