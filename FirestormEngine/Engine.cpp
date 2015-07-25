#include"Engine.h"
#include"Camera.h"
Engine::Engine()
{
	SDL_Init(0);
	graphicsSystem = std::shared_ptr<GraphicsSystem>(new GraphicsSystem(this));
	sceneSystem = std::shared_ptr<SceneSystem>(new SceneSystem(this));
	Startup();
}

void Engine::Startup()
{
	ReadInSettings();
	sceneSystem->StartUp();
	graphicsSystem->StartUp();
	Execute();
}

void Engine::ReadInSettings()
{
	// CHECK FOR MORE ERRORS HERE
	std::ifstream file("settings.config");
	std::vector<char> settings((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
	settings.push_back('\0');
	file.close();
	doc.parse<0>(&settings[0]);
	rapidxml::xml_node<>* root = doc.first_node();
	rapidxml::xml_node<>* node = root->first_node("GraphicsSystem");
	int width, height;
	//std::cout << "GraphicsSystem Node has value " << node->value() << std::endl;
	rapidxml::xml_attribute<>* myWidth = node->first_attribute("windowWidth");
	width = std::stoi(myWidth->value());
	rapidxml::xml_attribute<>* myHeight = node->first_attribute("windowHeight");
	height = std::stoi(myHeight->value());
	graphicsSystem->setWindowSize(width, height);
	node = root->first_node("SceneSystem");
	rapidxml::xml_attribute<>* scene = node->first_attribute();
	sceneSystem->ScenePath = scene->value();
}

int Engine::Execute()
{
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

}

void Engine::Shutdown()
{
	graphicsSystem->ShutDown();
	sceneSystem->ShutDown();
	SDL_Quit();
}

Engine::~Engine()
{
}