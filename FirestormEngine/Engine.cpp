#include"Engine.h"
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
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(window);
	glewExperimental = GL_TRUE;
	glewInit();
	graphicsSystem = new GraphicsSystem(this);
	Startup();
}

void Engine::Startup()
{
//	std::cout << "Engine Startup" << std::endl
//			  << "Calls ReadInSettings" << std::endl
//			  << "Instantiates and initializes each Engine System" << std::endl;
	ReadInSettings();
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
	graphicsSystem->LateUpdate();
	//std::cout << "Engine Update" << std::endl
	//	      << "Loops throughs systems and components and calls their update function" << std::endl;

}

void Engine::Shutdown()
{
	//std::cout << "Engine Shutdown" << std::endl
	//	      << "Calls all Shutdown behavior" << std::endl;
	SDL_GL_DeleteContext(context);
	SDL_Quit();
}

Engine::~Engine()
{
}