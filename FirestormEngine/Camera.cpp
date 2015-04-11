#include"Camera.h"
Camera::Camera(std::shared_ptr<Engine> _Engine, std::shared_ptr<Entity> _parent)
	: Component(_Engine, _parent)
{
	Name = "Camera";
}

Camera::~Camera()
{

}

void Camera::Update()
{

}

void Camera::LateUpdate()
{

}