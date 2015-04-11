#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<memory>
#include<GL\glew.h>
#include<SDL.h>
#include"GameSystem.h"
#include"GraphicsSystem.h"
#include"Engine.h"
#include"Entity.h"
#include"Component.h"
#include"Camera.h"
#include"ShaderProgram.h"
#include"Mesh.h"
#include"MeshRenderer.h"
#include"Material.h"

class GameSystem;
class Engine;
class GraphicsSystem;
class Entity;
class Component;
class Camera;
//class Shader;
class Mesh;
class MeshRenderer;
class Material;


class SceneSystem : public GameSystem
{
private:
public:
	GLuint VBO1, VBO2, VBO3, VBO4;
	glm::vec3 triangle1[3];
	glm::vec3 triangle2[3];
	glm::vec3 triangle3[3];
	glm::vec3 triangle4[3];
	GLint posAttrib;
	std::shared_ptr<Entity> Cube;
	std::shared_ptr<Entity> eMainCamera;
	std::shared_ptr<GraphicsSystem> graphicsSystem;
	std::shared_ptr<MeshRenderer> cubeRenderer;
	SceneSystem(std::shared_ptr<Engine> _engine);
	~SceneSystem();
	void StartUp();
	void Update();
	void LateUpdate();
	void ShutDown();
};