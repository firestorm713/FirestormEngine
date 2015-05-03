#include<SDL.h>
#include"GraphicsSystem.h"
#include"Engine.h"
GraphicsSystem::GraphicsSystem(Engine* _engine)
	:GameSystem(_engine)
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	GameWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL), [](SDL_Window* wind){ SDL_DestroyWindow(wind); });
	context = SDL_GL_CreateContext(GameWindow.get());
	glewExperimental = GL_TRUE;
	glewInit();
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}

GraphicsSystem::~GraphicsSystem()
{
}

void GraphicsSystem::StartUp()
{
}

void GraphicsSystem::Update()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsSystem::LateUpdate()
{
	SDL_GL_SwapWindow(GameWindow.get());
}

void GraphicsSystem::ShutDown()
{
	SDL_GL_DeleteContext(context);
}

void GraphicsSystem::setWindowSize(int w, int h)
{
	SDL_SetWindowSize(GameWindow.get(), w, h);
}

void GraphicsSystem::SetMainCamera(std::shared_ptr<Camera> cam)
{
	MainCamera = cam;
	std::shared_ptr<Entity> eCam = cam->GetParent();
	View_Matrix = glm::lookAt(eCam->transform->GetPosition(), eCam->transform->Forward(), eCam->transform->Up());
	Projection_Matrix = glm::perspective(cam->FoV, (float)(cam->width / cam->height), cam->NearClipPlane, cam->FarClipPlane);
	Projection_Matrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 10.0f);
	View_Matrix = glm::lookAt(
		cam->GetParent()->transform->Forward(),
		cam->GetParent()->transform->Right(),
		cam->GetParent()->transform->Up());
}