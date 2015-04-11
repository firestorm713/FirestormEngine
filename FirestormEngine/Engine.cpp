#include"Engine.h"
#include"Camera.h"
Engine::Engine()
{
	// std::cout << "Engine Constructor: Instantiation of engine." << std::endl
	// 		  << "Calls SDL_Init" << std::endl
	// 		  << "Calls Glew_Init" << std::endl
	// 		  << "Creates window and sets context" << std::endl;
	// TODO: Move SDL_Init(SDL_INIT_GRAPHICS) to GraphicsSystem
	// SDL_Init(0) in this function instead
	// all SDL_GL functions to Graphicssystem
	// Have window be specified when initializing GraphicsSystem and built there
	// move window, context and glewinit to GraphicsSystem.
	SDL_Init(0);
	graphicsSystem = std::shared_ptr<GraphicsSystem>(new GraphicsSystem(std::shared_ptr<Engine>(this)));
	sceneSystem = std::shared_ptr<SceneSystem>(new SceneSystem(std::shared_ptr<Engine>(this)));
	Startup();
}

void Engine::Startup()
{
//	std::cout << "Engine Startup" << std::endl
//			  << "Calls ReadInSettings" << std::endl
//			  << "Instantiates and initializes each Engine System" << std::endl;
	ReadInSettings();
	sceneSystem->StartUp();
	Execute();
}

void Engine::ReadInSettings()
{
//	std::cout <<"Engine ReadInSettings"<< std::endl
//		      << "Grabs Engine config file" << std::endl
//			  << "Reads in settings for each Engine System" << std::endl;
}

int Engine::Execute()
{
//	std::cout << "Engine Execute" << std::endl
//		      << "Starts game loop" << std::endl
//			  << "once game loop is complete, calls shutdown" << std::endl;
	running = true;
	while(running)
	{
		Update();
	}
	Shutdown();
	return 0;
}

void Engine::Update()
{
	if(SDL_PollEvent(&EngineEvent))
	{
		if(EngineEvent.type == SDL_KEYUP && EngineEvent.key.keysym.sym == SDLK_ESCAPE)
			running = false;
	}
	graphicsSystem->Update();
	sceneSystem->Update();
	graphicsSystem->LateUpdate();
	sceneSystem->Update();
	//std::cout << "Engine Update" << std::endl
	//	      << "Loops throughs systems and components and calls their update function" << std::endl;

}

void Engine::Shutdown()
{
	//std::cout << "Engine Shutdown" << std::endl
	//	      << "Calls all Shutdown behavior" << std::endl;
	SDL_Quit();
}

Engine::~Engine()
{
}