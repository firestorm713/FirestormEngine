#include"GraphicsSystem.h"

GraphicsSystem::GraphicsSystem(std::shared_ptr<Engine> _engine)
	:GameSystem(_engine)
{
	GameWindow = MainEngine->window;
}

GraphicsSystem::~GraphicsSystem()
{
}

void GraphicsSystem::StartUp()
{
}

void GraphicsSystem::Update()
{
}

void GraphicsSystem::ShutDown()
{
}