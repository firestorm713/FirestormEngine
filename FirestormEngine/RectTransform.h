#pragma once
#include<glm\glm.hpp>
#include"Component.h"

class RectTransform : public Component
{
private:
public:
	glm::vec2 Position;
	glm::vec2 Dimensions;
	float Rotation;
	glm::vec2 Scale;
	RectTransform(Engine* _engine, std::shared_ptr<Entity> parent);
	RectTransform(Engine* _engine, std::shared_ptr<Entity> parent, float x, float y, float w, float h);
	~RectTransform();
};