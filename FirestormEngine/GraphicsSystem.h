#pragma once
#include<SDL.h>
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<memory>
#include"GameSystem.h"
#include"Engine.h"
class Engine;
class GraphicsSystem : GameSystem
{
private:
	SDL_Window* GameWindow;
public:
	GraphicsSystem(std::shared_ptr<Engine> _engine);
	~GraphicsSystem();
	void StartUp();
	void Update();
	void ShutDown();
};