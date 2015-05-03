#pragma once
#include<memory>
#include"Mesh.h"
#include"Material.h"
#include"Component.h"
#include"Engine.h"
#include"GraphicsSystem.h"
#include"FlatTransformed.h"
class GraphicsSystem;

class MeshRenderer : public Component
{
private:
	GLuint VBO;
	GLuint EBO;
	GLuint UVBO;
	//GLuint NBO;
public:
	std::shared_ptr<GraphicsSystem> gSystem;
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<FlatTransformed> material;
	MeshRenderer(Engine* _Engine, std::shared_ptr<Entity> _parent, std::shared_ptr<FlatTransformed> _material);
	~MeshRenderer();
	void Update();
	void LateUpdate();
};