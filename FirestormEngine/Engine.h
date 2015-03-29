#pragma once
//#define GLEW_STATIC
#include<SDL.h>
#include<GL/glew.h>
#include<iostream>
#include<memory>
#include "GameSystem.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Startup();
	void ReadInSettings();
	int Execute();
	void Update();
	void Shutdown();
	SDL_Window* window;
	SDL_GLContext context;
	SDL_Event EngineEvent;
	bool running;
};