#pragma once
#include<SDL.h>
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<memory>
#include<vector>
//#include"Engine.h"
#include "Shader.h"
#include"GameSystem.h"
class Engine;
//class GameSystem;
class GraphicsSystem : public GameSystem
{
private:
	SDL_Window* GameWindow;
	GLuint VAO;
	GLuint VBO1, VBO2, VBO3, VBO4;
	glm::vec3 triangle1[3];
	glm::vec3 triangle2[3];
	glm::vec3 triangle3[3];
	glm::vec3 triangle4[3];
	ShaderProgram *shad;
	GLint posAttrib;
public:
	GraphicsSystem(Engine* _engine);
	~GraphicsSystem();
	void StartUp();
	void Update();
	void LateUpdate();
	void ShutDown();
};