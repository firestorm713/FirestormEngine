#include"GameSystem.h"

GameSystem::GameSystem(Engine* _engine)
{
	MainEngine = std::shared_ptr<Engine>(_engine);
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

void GameSystem::LateUpdate()
{
}

void GameSystem::ShutDown()
{
}