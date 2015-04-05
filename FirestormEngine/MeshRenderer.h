#pragma once
#include"Mesh.h"
#include"Material.h"
#include"Component.h"

class MeshRenderer : public Component
{
private:
	GLuint VBO;
	GLuint EBO;
public:
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
	MeshRenderer(Engine* _Engine, Entity* _parent, Mesh* _mesh, Material* _material);
	~MeshRenderer();
	void Update();
	void LateUpdate();
};