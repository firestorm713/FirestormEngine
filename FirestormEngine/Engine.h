#pragma once
//#define GLEW_STATIC
#include<SDL.h>
#include<GL/glew.h>
#include<iostream>
#include<memory>
#include<rapidxml.hpp>
#include"GraphicsSystem.h"
#include"SceneSystem.h"
//#include "GameSystem.h"
//#include "ShaderProgram.h"
#include "Entity.h"
//class GameSystem;
class GraphicsSystem;
class SceneSystem;
class Entity;

class Engine
{
	rapidxml::xml_document<> doc;
public:
	Engine();
	~Engine();
	void Startup();
	void ReadInSettings();
	int Execute();
	void Update();
	void Shutdown();
	SDL_Event EngineEvent;
	bool running;
	std::shared_ptr<GraphicsSystem> graphicsSystem;
	std::shared_ptr<SceneSystem> sceneSystem;
};