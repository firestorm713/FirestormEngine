#include"MeshRenderer.h"

MeshRenderer::MeshRenderer(std::shared_ptr<Engine> _Engine, std::shared_ptr<Entity> _parent)
	:Component(_Engine, _parent)
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &UVBO);
	Name = "MeshRenderer";
}

MeshRenderer::~MeshRenderer()
{
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &UVBO);
}
//void MeshRenderer::Update()
//{
//
//}
//
//void MeshRenderer::LateUpdate()
//{
//
//}
void MeshRenderer::Update()
{
	glUseProgram(material->Program);

	glUniformMatrix4fv(material->Model_Uniform, 1, GL_FALSE, glm::value_ptr(GetParent()->transform->GetTransformation()));
	glUniformMatrix4fv(material->View_Uniform, 1, GL_FALSE, glm::value_ptr(gSystem->View_Matrix));
	glUniformMatrix4fv(material->Projection_Uniform, 1, GL_FALSE, glm::value_ptr(gSystem->Projection_Matrix));

	glEnableVertexAttribArray(material->Position_Attribute);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh->Vertices), &mesh->Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(material->Position_Attribute, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(material->TexCoord_Attribute);
	glBindBuffer(GL_ARRAY_BUFFER, UVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh->UVs), &mesh->UVs, GL_STATIC_DRAW);
	glVertexAttribPointer(material->TexCoord_Attribute, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glActiveTexture(GL_TEXTURE0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, material->Texture->w, material->Texture->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, material->Texture->pixels);
	glUniform1i(material->Texture_Uniform, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mesh->Triangles), &mesh->Triangles, GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLES, mesh->Triangles.size(), GL_UNSIGNED_INT, 0);
}

void MeshRenderer::LateUpdate()
{
}