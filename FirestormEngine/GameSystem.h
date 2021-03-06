#pragma once
#include<memory>
//#include"Engine.h"
class Engine;

class GameSystem
{
public:
	GameSystem(Engine* _engine);
	~GameSystem();
	virtual void StartUp();
	virtual void Update();
	virtual void LateUpdate();
	virtual void ShutDown();
	Engine* MainEngine;
};