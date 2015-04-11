#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<memory>
#include"Component.h"
class Component;

__declspec(align(16))
class Transform
{
private:
	glm::mat4 Transformation;
	glm::mat4 View;
	glm::mat4 Projection;
	glm::mat4 Position_Mat;
	glm::mat4 Rotation_Mat;
	glm::mat4 Scale_Mat;
	//std::shared_ptr<glm::mat4> Parent;
	void PositionToMatrix();
	void RotationToMatrix();
	void ScaleToMatrix();
	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale;
public:
	Transform();
	~Transform();
	void Translate(glm::vec3 _pos);
	void Rotate(glm::vec3 _rot);
	glm::mat4 GetTransformation();
	void SetPosition(glm::vec3 _position);
	void SetRotation(glm::vec3 _rotation);
	void SetScale(glm::vec3 _scale);
	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();
};