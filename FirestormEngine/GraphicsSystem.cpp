#include<SDL.h>
#include"GraphicsSystem.h"
#include"Engine.h"
GraphicsSystem::GraphicsSystem(std::shared_ptr<Engine> _engine)
	:GameSystem(_engine)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	GameWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL), [](SDL_Window* wind){ SDL_DestroyWindow(wind); });
	context = SDL_GL_CreateContext(GameWindow.get());
	glewExperimental = GL_TRUE;
	glewInit();
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	//GameWindow = window;

	//glGenBuffers(1, &VBO1);
	//glGenBuffers(1, &VBO2);
	//glGenBuffers(1, &VBO3);
	//glGenBuffers(1, &VBO4);
	//
	//triangle1[0] = glm::vec3(-1,0,0);
	//triangle1[1] = glm::vec3(-0.5,1,0);
	//triangle1[2] = glm::vec3(0,0,0);
	//
	//triangle2[0] = glm::vec3(0,0,0);
	//triangle2[1] = glm::vec3(0.5,1,0);
	//triangle2[2] = glm::vec3(1,0,0);
	//
	//triangle3[0] = glm::vec3(-1,-1,0);
	//triangle3[1] = glm::vec3(-0.5,0,0);
	//triangle3[2] = glm::vec3(0,-1,0);
	//
	//triangle4[0] = glm::vec3(0,-1,0);
	//triangle4[1] = glm::vec3(0.5,0,0);
	//triangle4[2] = glm::vec3(1,-1,0);
	//ShaderProgram *shader = new ShaderProgram("basic.vertex", "basic.fragment");
	//shader->CompileShaders();
	//glUseProgram(shader->Program);
	//posAttrib = glGetAttribLocation(shader->Program, "position");
	//glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);
	//glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//glEnableVertexAttribArray(posAttrib);
}

GraphicsSystem::~GraphicsSystem()
{
	SDL_GL_DeleteContext(context);
}

void GraphicsSystem::StartUp()
{
}

void GraphicsSystem::Update()
{
	glClearColor(0.25f, 0.0f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicsSystem::LateUpdate()
{
	//glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);
	//glVertexAttribPointer(posAttrib,3,GL_FLOAT, GL_FALSE, 0,(void*)0);	
	//glDrawArrays(GL_TRIANGLES, 0,9);
	//
	//glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);
	//glVertexAttribPointer(posAttrib,3,GL_FLOAT, GL_FALSE, 0,(void*)0);
	//glDrawArrays(GL_TRIANGLES, 0,9);
	//
	//glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(triangle3), triangle3, GL_STATIC_DRAW);
	//glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//glDrawArrays(GL_TRIANGLES, 0,9);
	//
	//glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(triangle4), triangle4, GL_STATIC_DRAW);
	//glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//glDrawArrays(GL_TRIANGLES, 0,9);
	SDL_GL_SwapWindow(GameWindow.get());
}

void GraphicsSystem::ShutDown()
{
}

void GraphicsSystem::SetMainCamera(std::shared_ptr<Camera> cam)
{
	MainCamera = cam;
	std::shared_ptr<Entity> eCam = cam->GetParent();
	View_Matrix = eCam->transform->GetTransformation();
	Projection_Matrix = glm::perspective(cam->FoV, (float)(cam->width / cam->height), cam->NearClipPlane, cam->FarClipPlane);
}