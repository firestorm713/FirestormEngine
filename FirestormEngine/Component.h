#pragma once
#include<memory>
#include<string>
#include"Engine.h"
#include"Entity.h"
class Engine;
class Entity;

class Component
{
private:
	std::shared_ptr<Engine> engine;
	std::shared_ptr<Entity> parent;
public:
	Component(Engine* _Engine, Entity* _parent);
	~Component();
	virtual void Update();
	virtual void LateUpdate();
	std::weak_ptr<Entity> GetParent();
	std::string Name;
	virtual void Serialize();
};