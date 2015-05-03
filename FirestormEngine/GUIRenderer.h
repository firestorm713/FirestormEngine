#pragma once
#include<memory>
#include"Mesh.h"
#include"Material.h"
#include"Component.h"
#include"Engine.h"
#include"GraphicsSystem.h"
#include"GUIMaterial.h"

class GUIRenderer : public Component
{
private:

public:
	GLuint VBO;
	GLuint EBO;
	GLuint UVBO;
	float pos = 0;

	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<GUIMaterial> GUI_material;

	glm::vec2 Position;
	glm::vec2 Pivot;
	glm::vec2 Dimensions;
	float Rotation;
	glm::vec2 Scale;
	glm::mat3 Transformation;
	glm::mat3 Pos_Mat;
	glm::mat3 Rot_Mat;
	glm::mat3 Sca_Mat;
	
	void setPosition(float x, float y);
	void setPosition(glm::vec2 _Pos);
	void setDimensions(float w, float h);
	void setDimensions(glm::vec2 _Dim);
	void setRotation(float _Rot);
	void setScale(float x, float y);
	void setScale(glm::vec2 _Sca);

	GUIRenderer(Engine* _Engine, std::shared_ptr<Entity> _parent, std::shared_ptr<GUIMaterial> gui_material);
	~GUIRenderer();
	void Update();
	void LateUpdate();
};