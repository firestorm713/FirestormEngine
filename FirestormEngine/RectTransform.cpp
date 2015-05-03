#include "RectTransform.h"


RectTransform::RectTransform(Engine* _engine, std::shared_ptr<Entity> parent)
	:Component(_engine, parent)
{
	Position = glm::vec2(0, 0);
	Dimensions = glm::vec2(0, 0);
	Rotation = 0;
	Scale = glm::vec2(1, 1);
}

RectTransform::RectTransform(Engine* _engine, std::shared_ptr<Entity> parent, float x, float y, float w, float h)
	:Component(_engine, parent)
{
	Position = glm::vec2(x, y);
	Dimensions = glm::vec2(w, h);
	Rotation = 0;
	Scale = glm::vec2(1, 1);
}

RectTransform::~RectTransform()
{
}
