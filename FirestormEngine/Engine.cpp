#include"Engine.h"
#include"Camera.h"
Engine::Engine()
{
	// std::cout << "Engine Constructor: Instantiation of engine." << std::endl
	SDL_Init(0);
	graphicsSystem = std::shared_ptr<GraphicsSystem>(new GraphicsSystem(this));
	sceneSystem = std::shared_ptr<SceneSystem>(new SceneSystem(this));
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
	std::ifstream file("settings.config");
	std::vector<char> settings((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
	settings.push_back('\0');
	doc.parse<0>(&settings[0]);
	rapidxml::xml_node<>* root = doc.first_node();
	rapidxml::xml_node<>* node = doc.first_node()->first_node("GraphicsSystem");
	int width, height;
	std::cout << "GraphicsSystem Node has value " << node->value() << std::endl;
	rapidxml::xml_attribute<>* myWidth = node->first_attribute("windowWidth");
	width = std::stoi(myWidth->value());
	rapidxml::xml_attribute<>* myHeight = node->first_attribute("windowHeight");
	height = std::stoi(myHeight->value());
	graphicsSystem->setWindowSize(width, height);
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
	sceneSystem->LateUpdate();
	//std::cout << "Engine Update" << std::endl
	//	      << "Loops throughs systems and components and calls their update function" << std::endl;

}

void Engine::Shutdown()
{
	graphicsSystem->ShutDown();
	sceneSystem->ShutDown();
	//std::cout << "Engine Shutdown" << std::endl
	//	      << "Calls all Shutdown behavior" << std::endl;
	SDL_Quit();
}

Engine::~Engine()
{
}