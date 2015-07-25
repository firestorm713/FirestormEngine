#include"SceneSystem.h"

SceneSystem::SceneSystem(Engine* _engine)
	:GameSystem(_engine)
{
	SDL_InitSubSystem(SDL_TIMER_WINDOWS);
	graphicsSystem = _engine->graphicsSystem;
	
	//Box = std::shared_ptr<Entity>(new Entity());
}

void SceneSystem::StartUp()
{

	std::ifstream fin(ScenePath);
	std::vector <char> SceneFile((std::istreambuf_iterator<char>(fin)),
		std::istreambuf_iterator<char>());
	SceneFile.push_back('\0');
	fin.close();
	CurrentScene.parse<0>(&SceneFile[0]);
	rapidxml::xml_node<>* SceneRoot = CurrentScene.first_node();
	rapidxml::xml_node<>* eList = SceneRoot->first_node();
	for (rapidxml::xml_node<>* ent = eList->first_node(); ent; ent = ent->next_sibling())
	{
		std::shared_ptr<Entity> e = std::shared_ptr<Entity>(new Entity());
		EntityList.push_back(e);
		rapidxml::xml_attribute<>* eName = ent->first_attribute();
		e->Name = eName->value();
		rapidxml::xml_node<>* compList = ent->first_node();
		// loop through once we have more than just GUIRenderers
		rapidxml::xml_node<>* rend = compList->first_node();
		rapidxml::xml_node<>* mat = rend->first_node();
		std::shared_ptr<SDL_Surface> eSurf = std::shared_ptr<SDL_Surface>(IMG_Load(mat->first_attribute("texture")->value()), SDL_FreeSurface);
		std::shared_ptr<GUIMaterial> eMat = std::shared_ptr<GUIMaterial>(new GUIMaterial(eSurf));
		std::shared_ptr<GUIRenderer> eRend = std::shared_ptr<GUIRenderer>(new GUIRenderer(MainEngine, e, eMat));
		rapidxml::xml_attribute<>* attr = rend->first_attribute("Position");
		int x, y;
		char* tok = attr->value();
		std::string temp = strtok(tok, "(,");
		x = std::stoi(temp);
		temp = strtok(NULL, ",)");
		y = std::stoi(temp);
		eRend->setPosition(x, y);
		
		attr = attr->next_attribute();
		tok = attr->value();
		temp = strtok(tok, "(,");
		x = std::stoi(temp);
		temp = strtok(NULL, ",)");
		y = std::stoi(temp);
		eRend->setDimensions(x, y);
		
		attr = attr->next_attribute();
		tok = attr->value();
		eRend->setRotation(std::stoi(tok));

		attr = attr->next_attribute();
		tok = attr->value();
		temp = strtok(tok, "(,");
		x = std::stoi(temp);
		temp = strtok(NULL, ",)");
		y = std::stoi(temp);
		eRend->setScale(x, y);

		e->AddComponent(eRend);
	}
	//SDL_Surface* surf = IMG_Load("sample.png");
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	//std::shared_ptr<ShaderProgram> P = std::shared_ptr<ShaderProgram>(new ShaderProgram("basicTex.vertex","BasicTex.fragment"));
	//BoxMat = std::shared_ptr<GUIMaterial>(new GUIMaterial(P, std::shared_ptr<SDL_Surface>(surf, SDL_FreeSurface)));
	//GUIBox = std::shared_ptr<GUIRenderer>(new GUIRenderer(MainEngine, Box, BoxMat));
	//Box->AddComponent(GUIBox);
	//srand(AbsTime);
	
	//for (int i = 0; i < 10; i++)
	//{
	//	Boxes.push_back(std::shared_ptr<Entity>(new Entity));
	//	std::shared_ptr<GUIMaterial> tempMat = std::shared_ptr<GUIMaterial>(new GUIMaterial(P, std::shared_ptr<SDL_Surface>(surf, SDL_FreeSurface)));
	//	std::shared_ptr<GUIRenderer> tempRend = std::shared_ptr<GUIRenderer>(new GUIRenderer(MainEngine, Boxes[i], tempMat));
	//	tempRend->setPosition(float((float)(rand() % 100) / 100) - 0.5f, float((float)(rand() % 100) / 100) - 0.5f);
	//	Boxes[i]->AddComponent(tempRend);
	//}



	prevTime = SDL_GetTicks();

}

void SceneSystem::Update()
{
	AbsTime = SDL_GetTicks();
	deltaTime = AbsTime - prevTime;
	float col = (sin((float)AbsTime*0.001) + 1) / 2;
	float col2 = (cos((float)AbsTime*0.001) + 1) / 2;

	
	//GUIBox->setRotation(AbsTime*0.001f);
	//GUIBox->setScale(sin(AbsTime*0.001f), 1);
	//Box->Update();
	//for (int i = 0; i < Boxes.size(); i++)
	//{
	//	if (GUIRenderer* C = dynamic_cast<GUIRenderer*>(Boxes[i]->GetComponent("GUIRenderer").get()))
	//	{
	//		float rotation = C->Rotation;
	//		rotation+=.001;
	//		C->setRotation(rotation);
	//		glm::vec2 position = C->Position;
	//		position.y -= .001f;
	//		C->setPosition(position);
	//	}
	//	Boxes[i]->Update();
	//}
	for (int i = 0; i < EntityList.size(); i++)
	{
		EntityList[i]->Update();
	}
	prevTime = AbsTime;
}

void SceneSystem::LateUpdate()
{

}

void SceneSystem::ShutDown()
{

}

SceneSystem::~SceneSystem()
{
}