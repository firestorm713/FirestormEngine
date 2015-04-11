#include"SceneSystem.h"

SceneSystem::SceneSystem(std::shared_ptr<Engine> _engine)
	:GameSystem(_engine)
{
	eMainCamera = std::shared_ptr<Entity>(new Entity());
	graphicsSystem = std::shared_ptr<GraphicsSystem>(_engine->graphicsSystem);
	std::shared_ptr<Camera> Cam = std::shared_ptr<Camera>(new Camera(_engine, eMainCamera));
	eMainCamera->AddComponent(Cam);
	graphicsSystem->SetMainCamera(Cam);

	Cube = std::shared_ptr<Entity>(new Entity());

	// load a mesh
	glm::vec3 Vertices[] = { glm::vec3(-0.5, 0.5, 0.5), glm::vec3(0.5, 0.5, 0.5), glm::vec3(0.5, 0.5, -0.5), glm::vec3(-0.5, 0.5, -0.5),
		glm::vec3(-0.5, -0.5, 0.5), glm::vec3(0.5, -0.5, 0.5), glm::vec3(0.5, -0.5, -0.5), glm::vec3(-0.5, -0.5, -0.5) };
	int Triangles[] = {
		0, 1, 2, 0, 2, 3,
		4, 5, 1, 4, 1, 0,
		5, 6, 2, 5, 2, 1,
		7, 4, 0, 7, 0, 3,
		7, 6, 5, 7, 5, 4
	};
	glm::vec2 UVs[] = {
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(0, 1),			// Top
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(0, 1),			// Front
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(0, 1),			// Right
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(0, 1),			// Left
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(0, 1),			// Back
		glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(0, 1)			// Bottom
	};
	std::vector<glm::vec3> _verts(Vertices, Vertices + sizeof(Vertices) / sizeof(Vertices[0]));
	std::vector<int> _tris(Triangles, Triangles + sizeof(Triangles) / sizeof(Triangles[0]));
	
	std::shared_ptr<Mesh> cubeMesh = std::shared_ptr<Mesh>(new Mesh(_verts, _tris));
	cubeMesh->UVs = std::vector<glm::vec2>(UVs, UVs + sizeof(UVs) / sizeof(UVs[0]));
	
	std::shared_ptr<ShaderProgram> shad=std::shared_ptr<ShaderProgram>(new ShaderProgram("flatTextured.vertex", "flatTextured.fragment"));
	shad->CompileShaders();
	
	std::shared_ptr<Material> cubeMat = std::shared_ptr<Material>(new Material(shad));
	std::shared_ptr<SDL_Surface> texture = std::shared_ptr<SDL_Surface>(IMG_Load("sample.png"), SDL_FreeSurface);
	cubeMat->SetTexture(texture);
	
	cubeRenderer = std::shared_ptr<MeshRenderer>(new MeshRenderer(_engine, Cube));
	cubeRenderer->mesh = cubeMesh;
	cubeRenderer->material = cubeMat;
	cubeRenderer->gSystem = graphicsSystem;
	//MeshRenderer* cubeRenderer = new MeshRenderer(MainEngine.get(), Cube.get(), cubeMesh.get(), cubeMat.get());
	
	//std::shared_ptr<MeshRenderer> mRenderer(new MeshRenderer(_engine, Cube));
	//mRenderer->gSystem = graphicsSystem;
	//mRenderer->mesh = cubeMesh;
	Cube->AddComponent(cubeRenderer);
	Cube->transform->SetPosition(glm::vec3(0,0,-10));
}

SceneSystem::~SceneSystem()
{
	
}

void SceneSystem::StartUp()
{
	glGenBuffers(1, &VBO1);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &VBO3);
	glGenBuffers(1, &VBO4);
	
	triangle1[0] = glm::vec3(-1,0,0);
	triangle1[1] = glm::vec3(-0.5,1,0);
	triangle1[2] = glm::vec3(0,0,0);
	
	triangle2[0] = glm::vec3(0,0,0);
	triangle2[1] = glm::vec3(0.5,1,0);
	triangle2[2] = glm::vec3(1,0,0);
	
	triangle3[0] = glm::vec3(-1,-1,0);
	triangle3[1] = glm::vec3(-0.5,0,0);
	triangle3[2] = glm::vec3(0,-1,0);
	
	triangle4[0] = glm::vec3(0,-1,0);
	triangle4[1] = glm::vec3(0.5,0,0);
	triangle4[2] = glm::vec3(1,-1,0);
	ShaderProgram *shader = new ShaderProgram("basic.vertex", "basic.fragment");
	shader->CompileShaders();
	glUseProgram(shader->Program);
	posAttrib = glGetAttribLocation(shader->Program, "position");
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(posAttrib);
}

void SceneSystem::Update()
{

	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);
	glVertexAttribPointer(posAttrib,3,GL_FLOAT, GL_FALSE, 0,(void*)0);	
	glDrawArrays(GL_TRIANGLES, 0,9);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);
	glVertexAttribPointer(posAttrib,3,GL_FLOAT, GL_FALSE, 0,(void*)0);
	glDrawArrays(GL_TRIANGLES, 0,9);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle3), triangle3, GL_STATIC_DRAW);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0,9);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle4), triangle4, GL_STATIC_DRAW);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0,9);
	eMainCamera->transform->Rotate(glm::vec3(1, 0, 0));
	Cube->Update();
	eMainCamera->Update();
}

void SceneSystem::LateUpdate()
{

}

void SceneSystem::ShutDown()
{
}