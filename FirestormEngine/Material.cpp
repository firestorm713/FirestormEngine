#include"Material.h"
Material::Material(std::shared_ptr<ShaderProgram> shader_program)
{
	Shader_Program = shader_program;
	Shader_Program->CompileShaders();
	Program = Shader_Program->Program;
	Position_Attribute = glGetAttribLocation(Program, "position");
	Color_Uniform = glGetUniformLocation(Program, "color");
	glUniform3f(Color_Uniform, 1.0f, 1.0f, 1.0f);
}

Material::~Material()
{
}

void Material::RefreshTexture()
{
}