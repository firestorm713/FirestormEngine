#pragma once
#include<SDL.h>
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<memory>
#include<vector>
//#include"Engine.h"
#include "ShaderProgram.h"
#include"GameSystem.h"
#include"Camera.h"
class Camera;
class Engine;
//class GameSystem;
__declspec(align(16))
class GraphicsSystem : public GameSystem
{
private:
	std::shared_ptr<SDL_Window> GameWindow;
	GLuint VAO;
	SDL_GLContext context;
	std::shared_ptr<Camera> MainCamera;
	int ScreenWidth;
	int ScreenHeight;
public:
	glm::mat4 Projection_Matrix;
	glm::mat4 View_Matrix;
	GraphicsSystem(Engine* _engine);
	~GraphicsSystem();
	void StartUp();
	void Update();
	void LateUpdate();
	void ShutDown();
	void setWindowSize(int w, int h);
	void SetMainCamera(std::shared_ptr<Camera> cam);
};