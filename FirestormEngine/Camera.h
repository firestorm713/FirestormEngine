#pragma once
#include<glm\glm.hpp>
#include<memory.h>
#include"GraphicsSystem.h"
//#include"Entity.h"
#include"Component.h"
//#include"Transform.h"
class Entity;
class Component;

class Camera : public Component
{
private:
public:
	int width, height;
	float AspectRatio;
	float FoV;
	//std::shared_ptr<Transform> transform;
	float NearClipPlane;
	float FarClipPlane;
	glm::vec3 BackgroundColor;
	Camera(Engine* _Engine, std::shared_ptr<Entity> _parent);
	~Camera();
	virtual void Update();
	virtual void LateUpdate();
};