#pragma once
#include<iostream>
#include<GL\glew.h>
#include<memory>
#include<string>
#include<fstream>
class ShaderProgram
{
private:
	std::string vertexShader;
	std::string fragmentShader;
	std::ifstream fin;
	std::ofstream fout;
	GLuint vertexShaderID;
	GLuint fragmentShaderID;
public:
	ShaderProgram();
	ShaderProgram(std::string vertSourcePath, std::string fragSourcePath); 
	~ShaderProgram();
	void CompileShaders();
	GLuint Program;
};