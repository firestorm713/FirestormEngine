#include"Shader.h"
#include<stdio.h>
#include<vector>
#include<algorithm>

const char* VertexShaderSource =    "#version 150 core\n"
    "in vec2 position;"
    "in vec3 color;"
    "out vec3 Color;"
    "void main() {"
    "   Color = color;"
    "   gl_Position = vec4(position, 0.0, 1.0);"
    "}";

const char* FragmentShaderSource = "#version 150 core\n"
    "in vec3 Color;"
    "out vec4 outColor;"
    "void main() {"
    "   outColor = vec4(Color, 1.0);"
    "}";

ShaderProgram::ShaderProgram()
{

}

ShaderProgram::ShaderProgram(std::string vertSourcePath, std::string fragSourcePath)
{
	fin.open(vertSourcePath, std::ios::in);
	//std::string vert((std::istreambuf_iterator<char>(fin)), (std::istreambuf_iterator<char>()));
	//vertexShader = vert;
	//vertexShader.assign((std::istreambuf_iterator<char>(fin)), (std::istreambuf_iterator<char>()));
	//vertexShader[vertexShader.length()] = '\0';
	//vertexShader += '\0';
	//std::cout << vertexShader << std::endl;
	std::string Line = ""; 
	while(getline(fin, Line))
		vertexShader +="\n" + Line;
	fin.close();

	fin.open(fragSourcePath);
	Line = "";
	while(getline(fin, Line))
		fragmentShader += "\n" + Line;
	//std::string frag((std::istreambuf_iterator<char>(fin)), (std::istreambuf_iterator<char>()));
	//fragmentShader = frag;
	//fragmentShader.assign((std::istreambuf_iterator<char>(fin)), (std::istreambuf_iterator<char>()));
	//fragmentShader[fragmentShader.length()] = '\0';
	//fragmentShader += '\0';
	//std::cout << fragmentShader << std::endl;
	fin.close();
}

void ShaderProgram::CompileShaders()
{
	const GLchar* vertSource = vertexShader.c_str();
	const GLchar* fragSource = fragmentShader.c_str();
	GLint const vert_length = vertexShader.size();
	GLint const frag_length = fragmentShader.size();

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(vertexShaderID, 1, (const GLchar**)&vertSource, &vert_length);
	glShaderSource(vertexShaderID, 1, &vertSource, NULL);
	glCompileShader(vertexShaderID);
	GLint status;
	int infoLogLength;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &status);
	glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	// later assert GLint status == GL_TRUE
	if(status != GL_TRUE)
	{
		std::vector<char> buffer(infoLogLength);
		glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &buffer[0]);
		printf("%s\n",&buffer[0]);
		//std::cout << &buffer[0] << std::endl;
	}

	//glShaderSource(fragmentShaderID, 1, (const GLchar**)&fragSource, &frag_length);
	glShaderSource(fragmentShaderID, 1, &fragSource, NULL);
	glCompileShader(fragmentShaderID);

	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &status);
	glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if(status != GL_TRUE)
	{
		std::vector<char> buffer(infoLogLength);
		glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &buffer[0]);
		buffer[0] = '\0';
		printf("%s\n",&buffer[0]);
		//std::cout << &buffer[0] << std::endl;
	}
	Program = glCreateProgram();
	glAttachShader(Program, vertexShaderID);
	glAttachShader(Program, fragmentShaderID);
	glBindFragDataLocation(Program, 0, "outColor");
	glLinkProgram(Program);

	glGetProgramiv(Program, GL_COMPILE_STATUS, &status);
	glGetProgramiv(Program, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> ProgramErrorMessage(std::max(infoLogLength, int(1)));
	printf("%s\n",&ProgramErrorMessage[0]);
}