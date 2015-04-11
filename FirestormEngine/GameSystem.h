#pragma once
#include<memory>
//#include"Engine.h"
class Engine;

class GameSystem
{
public:
	GameSystem(std::shared_ptr<Engine> _engine);
	~GameSystem();
	virtual void StartUp();
	virtual void Update();
	virtual void LateUpdate();
	virtual void ShutDown();
	std::shared_ptr<Engine> MainEngine;
};