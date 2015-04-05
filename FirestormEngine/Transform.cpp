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

glm::mat4 Transform::PositionToMatrix()
{
	Position_Mat = glm::mat4();
	glm::translate(Position_Mat, Position);
	Transformation=Position_Mat*Rotation_Mat*Scale_Mat;
}

glm::mat4 Transform::RotationToMatrix()
{
	Rotation_Mat = glm::mat4();
	glm::rotate(Rotation_Mat, Rotation.x, glm::vec3(1,0,0));
	glm::rotate(Rotation_Mat, Rotation.y, glm::vec3(0,1,0));
	glm::rotate(Rotation_Mat, Rotation.z, glm::vec3(0,0,1));
	Transformation = Position_Mat*Rotation_Mat*Scale_Mat;
}

glm::mat4 Transform::ScaleToMatrix()
{
	Scale_Mat = glm::mat4();
	glm::scale(Scale_Mat, Scale);
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
	PositionToMatrix;
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