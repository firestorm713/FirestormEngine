#include"Entity.h"

Entity::Entity()
{
	transform = std::shared_ptr<Transform>(new Transform());
}

Entity::~Entity()
{
}

void Entity::AddComponent(Component* _component)
{
	ComponentList.push_back(std::shared_ptr<Component>(_component));
}

void Entity::AddComponent(std::shared_ptr<Component> _component)
{
	ComponentList.push_back(_component);
}

void Entity::RemoveComponent(Component* _component)
{
	for(int i = 0; i < ComponentList.size(); i++)
	{
		if(ComponentList[i] == std::shared_ptr<Component>(_component))
		{
			ComponentList.erase(ComponentList.begin()+i);
			return;
		}
	}
}

std::shared_ptr<Component> Entity::GetComponent(std::string ComponentName)
{
	for(int i = 0; i < ComponentList.size(); i++)
	{
		if(ComponentList[i]->Name == ComponentName)
			return ComponentList[i];
	}
	return NULL;
}

void Entity::Serialize()
{
	for(int i = 0; i < ComponentList.size(); i++)
	{
		ComponentList[i]->Serialize();
	}
}

void Entity::Update()
{
	std::vector<std::shared_ptr<Component>>::iterator it;
	if (ComponentList.size() != 0)
	{
		for (it = ComponentList.begin(); it != ComponentList.end(); it++)
		{
			(*it)->Update();
		}
	}
}