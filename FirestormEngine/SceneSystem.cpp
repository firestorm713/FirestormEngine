#include"SceneSystem.h"

SceneSystem::SceneSystem(Engine* _engine)
	:GameSystem(_engine)
{
	SDL_InitSubSystem(SDL_TIMER_WINDOWS);
	graphicsSystem = _engine->graphicsSystem;
	//GUIFrame = std::shared_ptr<Entity>(new Entity());
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &UVBO);
	glGenBuffers(1, &EBO);
	glGenTextures(1, &Tex_Object);
	SProgram = std::shared_ptr<ShaderProgram>(new ShaderProgram("basic.vertex", "basic.fragment"));
	SProgram->CompileShaders();
	Program1 = SProgram->Program;
	texShader = std::shared_ptr<ShaderProgram>(new ShaderProgram("basicTex.vertex", "basicTex.fragment"));
	texShader->CompileShaders();
	Program2 = texShader->Program;
	TransShader = std::shared_ptr<ShaderProgram>(new ShaderProgram("flatTextured.vertex", "flatTextured.fragment"));
	TransShader->CompileShaders();
	Program3 = TransShader->Program;
	Box = std::shared_ptr<Entity>(new Entity());
}

void SceneSystem::StartUp()
{
	
	Position_Attribute = glGetAttribLocation(Program1, "position");
	Color_Uniform = glGetUniformLocation(Program1, "Color");
	TPos_Attribute = glGetAttribLocation(Program2, "position");
	
	TCol_Uniform = glGetUniformLocation(Program2, "color");
	TCor_Attribute = glGetAttribLocation(Program2, "texcoord");
	Tex_Uniform = glGetUniformLocation(Program2, "tex");
	Trans_Uniform = glGetUniformLocation(Program2, "Trans");

	PPos_Attribute = glGetAttribLocation(Program3, "position");
	PCor_Attribute = glGetAttribLocation(Program3, "texcoord");
	PCol_Uniform   = glGetUniformLocation(Program3, "color");
	PTex_Uniform   = glGetUniformLocation(Program3, "tex");
	Model_Uniform  = glGetUniformLocation(Program3, "model");
	View_Uniform   = glGetUniformLocation(Program3, "view");
	Proj_Uniform   = glGetUniformLocation(Program3, "proj");

	SDL_Surface* surf = IMG_Load("sample.png");
	glBindTexture(GL_TEXTURE_2D, Tex_Object);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
	glUniform1i(Tex_Uniform, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	std::shared_ptr<ShaderProgram> P = std::shared_ptr<ShaderProgram>(new ShaderProgram("basicTex.vertex","BasicTex.fragment"));
	//P->CompileShaders();
	BoxMat = std::shared_ptr<GUIMaterial>(new GUIMaterial(P, std::shared_ptr<SDL_Surface>(surf, SDL_FreeSurface)));
	GUIBox = std::shared_ptr<GUIRenderer>(new GUIRenderer(MainEngine, Box, BoxMat));
	Box->AddComponent(GUIBox);
	srand(AbsTime);
	
	for (int i = 0; i < 100; i++)
	{
		Boxes.push_back(std::shared_ptr<Entity>(new Entity));
		std::shared_ptr<GUIMaterial> tempMat = std::shared_ptr<GUIMaterial>(new GUIMaterial(P, std::shared_ptr<SDL_Surface>(surf, SDL_FreeSurface)));
		std::shared_ptr<GUIRenderer> tempRend = std::shared_ptr<GUIRenderer>(new GUIRenderer(MainEngine, Boxes[i], tempMat));
		tempRend->setPosition(float((float)(rand() % 100) / 100) - 0.5f, float((float)(rand() % 100) / 100) - 0.5f);
		Boxes[i]->AddComponent(tempRend);
	}

	std::vector<glm::vec3> Vertices = { glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(-0.5f, 1.0f, 0.0f), glm::vec3(-1.0f, 0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f) };
	std::vector<glm::vec3> texQ = { glm::vec3(0.5f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), 
									glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.5f, 0.0f) };
	std::vector<int> Triangles = {0,1,2,1,3,2};
	std::vector<glm::vec2> UVs = { glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(0, 1), glm::vec2(1, 1) };

	std::vector<glm::vec3> CubeVerts = { 
		glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(-0.5f, 0.5f, -0.5f),
		glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(-0.5f, 0.5f, 0.5f) };
	std::vector<glm::vec2> CubeUVsTemp = { 
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1),
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 1) };
	std::vector<int> CubeTriangles = { 
		0, 2, 1, 0, 3, 2,
		4, 6, 5, 4, 7, 6,
		0, 7, 4, 0, 3, 7,
		5, 2, 1, 5, 6, 2,
		7, 2, 6, 7, 3, 2,
		0, 5, 1, 0, 4, 5 };

	model = glm::mat4(1.0);
	view = glm::lookAt(
		glm::vec3(1.2f, 1.2f, 1.2f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
		);
	proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 10.0f);

	std::copy(Vertices.begin(), Vertices.end(), Quad);
	std::copy(UVs.begin(), UVs.end(), QuadUV);
	
	std::copy(texQ.begin(), texQ.end(), TexQuad);
	std::copy(Triangles.begin(), Triangles.end(), QuadTris);
	
	std::copy(CubeVerts.begin(), CubeVerts.end(), Cube);
	std::copy(CubeUVsTemp.begin(), CubeUVsTemp.end(), CubeUV);
	std::copy(CubeTriangles.begin(), CubeTriangles.end(), CubeTris);

	glUniform3f(Color_Uniform, 1.0f, 1.0f, 0.0f);
	glUniform3f(TCol_Uniform, 1.0f, 1.0f, 0.0f);
	
	glUniform3f(PCol_Uniform, 1.0f, 1.0f, 0.0f);
	glUniform1i(PTex_Uniform, 0);
	glUniformMatrix4fv(Model_Uniform, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(View_Uniform, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(Proj_Uniform, 1, GL_FALSE, glm::value_ptr(proj));
	glm::mat3 id = glm::mat3(1);
	glUniformMatrix3fv(Trans_Uniform, 1, GL_FALSE, glm::value_ptr(id));

	prevTime = SDL_GetTicks();

}

void SceneSystem::Update()
{
	AbsTime = SDL_GetTicks();
	deltaTime = AbsTime - prevTime;
	float col = (sin((float)AbsTime*0.001) + 1) / 2;
	float col2 = (cos((float)AbsTime*0.001) + 1) / 2;

	
	GUIBox->setRotation(AbsTime*0.001f);
	GUIBox->setScale(sin(AbsTime*0.001f), 1);
	Box->Update();
	for (int i = 0; i < Boxes.size(); i++)
	{
		
		if (GUIRenderer* C = dynamic_cast<GUIRenderer*>(Boxes[i]->GetComponent("GUIRenderer").get()))
		{
			float rotation = C->Rotation;
			rotation+=.001;
			C->setRotation(rotation);
			glm::vec2 position = C->Position;
			position.y -= .001f;
			C->setPosition(position);
		}
		Boxes[i]->Update();
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