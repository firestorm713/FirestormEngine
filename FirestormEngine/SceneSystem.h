#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<memory>
#include<GL\glew.h>
#include<SDL.h>
#include<math.h>
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
	GLuint VBO;
	GLuint UVBO;
	GLuint EBO;
	glm::vec3 Quad[4];
	glm::vec2 QuadUV[4];
	unsigned int QuadTris[6];
	
	std::shared_ptr<ShaderProgram> SProgram;
	GLuint Program1;
	GLint Position_Attribute;
	GLint Color_Uniform;

	std::shared_ptr<ShaderProgram> texShader;
	GLuint Program2;
	glm::vec3 TexQuad[4];
	GLint TPos_Attribute;
	GLint TCor_Attribute;
	GLint TCol_Uniform;
	GLuint Tex_Object;
	GLint Tex_Uniform;
	GLint Trans_Uniform;

	std::shared_ptr<ShaderProgram> TransShader;
	GLuint Program3;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
	glm::vec3 Cube[8];
	glm::vec2 CubeUV[8];
	unsigned int CubeTris[36];
	GLint PPos_Attribute;
	GLint PCor_Attribute;
	GLint PCol_Uniform;
	//GLuint PTex_Object;
	GLint PTex_Uniform;
	GLint Model_Uniform;
	GLint View_Uniform;
	GLint Proj_Uniform;
	
	unsigned int AbsTime;
	unsigned int prevTime;
	unsigned int deltaTime;

	std::shared_ptr<Entity> Box;
	std::shared_ptr<GUIRenderer> GUIBox;
	std::shared_ptr<GUIMaterial> BoxMat;

	std::vector<std::shared_ptr<Entity>> Boxes;

	std::shared_ptr<GraphicsSystem> graphicsSystem;
	//std::shared_ptr<Entity> GUIFrame;
	SceneSystem(Engine* _engine);
	~SceneSystem();
	void StartUp();
	void Update();
	void LateUpdate();
	void ShutDown();
};