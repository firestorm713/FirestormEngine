#include"GUIRenderer.h"
GUIRenderer::GUIRenderer(Engine* _Engine, std::shared_ptr<Entity> _parent, std::shared_ptr<GUIMaterial> gui_material)
	:Component(_Engine, _parent)
{
	GUI_material = gui_material;
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &UVBO);
	Name = "GUIRenderer";
	Dimensions = glm::vec2(1, 1);
	std::vector<glm::vec3> verts = { glm::vec3(-Dimensions.x/2.0f, Dimensions.y/2.0f, 1.0f),  glm::vec3(Dimensions.x/2.0f, Dimensions.y/2.0f, 1.0f), 
								     glm::vec3(-Dimensions.x/2.0f, -Dimensions.y/2.0f, 1.0f), glm::vec3(Dimensions.x/2.0f, -Dimensions.y/2.0f, 1.0f) };
	std::vector<glm::vec2> uvs = { glm::vec2(0, 0), glm::vec2(1, 0), 
								   glm::vec2(0, 1), glm::vec2(1, 1) };
	std::vector<int> tris = { 0,1,2,2,1,3 };
	mesh = std::shared_ptr<Mesh>(new Mesh(verts, tris, uvs));
	Sca_Mat = glm::mat3(1);
	Rot_Mat = glm::mat3(1);
	Pos_Mat = glm::mat3(1);
	Transformation = glm::mat3(1);
	setPosition(0, 0);
	setRotation(3.141/2);
	setScale(0.5, 0.5);
}

GUIRenderer::~GUIRenderer()
{

}

void GUIRenderer::setPosition(float x, float y)
{
	Position = glm::vec2(x, y);
	Pos_Mat = glm::mat3(
		1, 0, 0,				//1, 0, x,
		0, 1, 0,				//0, 1, y,
		x, y, 1					//0, 0, 1
		);
	Transformation = Pos_Mat*Rot_Mat*Sca_Mat;
}

void GUIRenderer::setPosition(glm::vec2 _Pos)
{
	setPosition(_Pos.x, _Pos.y);
}

void GUIRenderer::setDimensions(float w, float h)
{

}

void GUIRenderer::setDimensions(glm::vec2 _Dim)
{

}

void GUIRenderer::setRotation(float _Rot)
{
	Rotation = _Rot;
	Rot_Mat = glm::mat3(
		cos(Rotation), sin(Rotation), 0,
		-sin(Rotation), cos(Rotation), 0,
		0, 0, 1
		);
	Transformation = Pos_Mat*Rot_Mat*Sca_Mat;
}

void GUIRenderer::setScale(float x, float y)
{
	Scale = glm::vec2(x, y);
	Sca_Mat = glm::mat3(
		x, 0, 0,
		0, y, 0,
		0, 0, 1
		);
	Transformation = Pos_Mat*Rot_Mat*Sca_Mat;
}

void GUIRenderer::setScale(glm::vec2 _Sca)
{
	setScale(_Sca.x, _Sca.y);
}

void GUIRenderer::Update()
{
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glUseProgram(GUI_material->Program);
	glUniform3f(GUI_material->Color_Uniform, 1.0f, 1.0f, 1.0f);

	glUniformMatrix3fv(GUI_material->Trans_Uniform, 1, GL_FALSE, &Transformation[0][0]);
	GUI_material->RefreshTexture();
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mesh->Vertices.size()*sizeof(glm::vec3), &mesh->Vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(GUI_material->Position_Attribute);
	glVertexAttribPointer(GUI_material->Position_Attribute, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, UVBO);
	glBufferData(GL_ARRAY_BUFFER, mesh->UVs.size()*sizeof(glm::vec2), &mesh->UVs[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(GUI_material->TexCoord_Attribute);
	glVertexAttribPointer(GUI_material->TexCoord_Attribute, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->Triangles.size()*sizeof(int), &mesh->Triangles[0], GL_STATIC_DRAW);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDisable(GL_BLEND);
}

void GUIRenderer::LateUpdate()
{
}