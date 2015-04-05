#include"Component.h"

Component::Component(Engine* _engine, Entity* _parent)
{
	engine = std::shared_ptr<Engine>(_engine);
	parent = std::shared_ptr<Entity>(_parent);
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

std::weak_ptr<Entity> Component::GetParent()
{
	return std::weak_ptr<Entity>(parent);
}

void Component::Serialize()
{
}