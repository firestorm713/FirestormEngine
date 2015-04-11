#include"Component.h"

Component::Component(std::shared_ptr<Engine> _engine, std::shared_ptr<Entity> _parent)
{
	engine = _engine;
	parent = _parent;
	Name = "";
}

Component::~Component()
{
}

void Component::Update()
{
}

void Component::LateUpdate()
{
}

std::shared_ptr<Entity> Component::GetParent()
{
	return parent;
}

void Component::Serialize()
{
}