#include"Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::AddComponent(Component* _component)
{
	ComponentList.push_back(std::shared_ptr<Component>(_component));
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