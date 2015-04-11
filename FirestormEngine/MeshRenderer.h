#pragma once
#include<memory>
#include"Mesh.h"
#include"Material.h"
#include"Component.h"
#include"Engine.h"
#include"GraphicsSystem.h"
class GraphicsSystem;

class MeshRenderer : public Component
{
private:
	GLuint VBO;
	GLuint EBO;
	GLuint UVBO;
public:
	std::shared_ptr<GraphicsSystem> gSystem;
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
	MeshRenderer(std::shared_ptr<Engine> _Engine, std::shared_ptr<Entity> _parent);
	~MeshRenderer();
	void Update();
	void LateUpdate();
};