#include"Camera.h"
Camera::Camera(Engine* _Engine, std::shared_ptr<Entity> _parent)
	: Component(_Engine, _parent)
{
	Name = "Camera";
	FoV = 45.0f;
	NearClipPlane = 0.01f;
	FarClipPlane = 1000.0f;
	width = 800;
	height = 600;
	AspectRatio = 4.0f / 3.0f;
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