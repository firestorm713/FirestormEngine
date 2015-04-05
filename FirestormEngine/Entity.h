#pragma once
#include<vector>
#include<memory>
#include<string>
#include"Component.h"
#include"Transform.h"
class Transform;
class Component;
class Entity
{
private:
	std::vector<std::shared_ptr<Component>> ComponentList;
public:
	Entity();
	~Entity();
	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
	std::shared_ptr<Component> GetComponent(std::string ComponentName);
	void Serialize();
};