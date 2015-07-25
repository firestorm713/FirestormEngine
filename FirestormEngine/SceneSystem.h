#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<memory>
#include<GL\glew.h>
#include<SDL.h>
#include<math.h>
#include<rapidxml.hpp>
#include"GameSystem.h"
#include"GraphicsSystem.h"
#include"Engine.h"
#include"Entity.h"
#include"Component.h"
#include"Camera.h"
#include"ShaderProgram.h"
#include"Mesh.h"
#include"MeshRenderer.h"
#include"FlatTransformed.h"
#include"GUIMaterial.h"
#include"GUIRenderer.h"
class GUIRenderer;

class SceneSystem : public GameSystem
{
private:
public:
	// TEMPORARY, YOU NEED TO MAKE THE WHOLE GAME AWARE OF TIME
	unsigned int AbsTime;
	unsigned int prevTime;
	unsigned int deltaTime;

	std::shared_ptr<Entity> Box;
	std::shared_ptr<GUIRenderer> GUIBox;
	std::shared_ptr<GUIMaterial> BoxMat;

	std::vector<std::shared_ptr<Entity>> Boxes;

	std::shared_ptr<GraphicsSystem> graphicsSystem;

	std::string ScenePath;
	rapidxml::xml_document<> CurrentScene;
	std::vector<std::shared_ptr<Entity>> EntityList;
	
	//std::shared_ptr<Entity> GUIFrame;
	SceneSystem(Engine* _engine);
	~SceneSystem();
	void StartUp();
	void Update();
	void LateUpdate();
	void ShutDown();
};