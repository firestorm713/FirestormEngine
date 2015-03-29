#include"GameSystem.h"

GameSystem::GameSystem(std::shared_ptr<Engine> _engine)
{
	MainEngine = _engine;
}

GameSystem::~GameSystem()
{
}

void GameSystem::StartUp()
{
}

void GameSystem::Update()
{
}

void GameSystem::ShutDown()
{
}