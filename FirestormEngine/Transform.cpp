#include"Transform.h"

Transform::Transform()
{
	Position = glm::vec3(0,0,0);
	Rotation = glm::vec3(0,0,0);
	Scale = glm::vec3(0,0,0);
	Position_Mat = glm::mat4();
	Rotation_Mat = glm::mat4();
	Scale_Mat = glm::mat4();
}

Transform::~Transform()
{
}

void Transform::PositionToMatrix()
{
	Position_Mat = glm::mat4(
		1, 0, 0, Position.x,
		0, 1, 0, Position.y,
		0, 0, 1, Position.z,
		0, 0, 0, 1
		);
	Transformation = Position_Mat*Rotation_Mat*Scale_Mat;
}

void Transform::RotationToMatrix()
{
	Rotation_Mat = glm::mat4(
		1, 0, 0, 0,
		0, cos(Rotation.x), -sin(Rotation.x), 0,
		0, sin(Rotation.x), cos(Rotation.x), 0,
		0, 0, 0, 1
		)*glm::mat4(
		cos(Rotation.y), 0, sin(Rotation.y), 0,
		0, 1, 0, 0,
		-sin(Rotation.y), 0, cos(Rotation.y), 0,
		0, 0, 0, 1
		)*glm::mat4(
		cos(Rotation.z), -sin(Rotation.z), 0, 0,
		sin(Rotation.z), cos(Rotation.z), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
	Transformation = Position_Mat*Rotation_Mat*Scale_Mat;
}

void Transform::ScaleToMatrix()
{
	Scale_Mat = glm::mat4(
		Scale.x, 0, 0, 0,
		0, Scale.y, 0, 0,
		0, 0, Scale.z, 0,
		0, 0, 0, 1
		);
	Transformation = Position_Mat*Rotation_Mat*Scale_Mat;
}

void Transform::Translate(glm::vec3 _pos)
{
	Position += _pos;
	PositionToMatrix();
}

void Transform::Rotate(glm::vec3 _rot)
{
	Rotation+= _rot;
	RotationToMatrix();
}

glm::mat4 Transform::GetTransformation()
{
	return Transformation;
}

void Transform::SetPosition(glm::vec3 _position)
{
	Position = _position;
	PositionToMatrix();
}

void Transform::SetRotation(glm::vec3 _rotation)
{
	Rotation = _rotation;
	RotationToMatrix();
}

void Transform::SetScale(glm::vec3 _scale)
{
	Scale = _scale;
	ScaleToMatrix();
}

glm::vec3 Transform::GetPosition()
{
	return Position;
}

glm::vec3 Transform::GetRotation()
{
	return Rotation;
}

glm::vec3 Transform::GetScale()
{
	return Scale;
}

glm::vec3 Transform::Forward()
{
	return glm::vec3(
		cos(Rotation.x)*sin(Rotation.z),
		sin(Rotation.x),
		cos(Rotation.x)*cos(Rotation.z)
		);
}

glm::vec3 Transform::Right()
{
	return glm::vec3(
		sin(Rotation.z - 3.14f / 2.0f),
		0,
		cos(Rotation.z - 3.14f / 2.0f)
		);
}

glm::vec3 Transform::Up()
{
	return glm::cross(Right(), Forward());
}