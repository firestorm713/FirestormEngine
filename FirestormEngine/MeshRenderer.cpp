#include"MeshRenderer.h"

MeshRenderer::MeshRenderer(Engine* _Engine, Entity* _parent, Mesh* _mesh, Material* _material)
	:Component(_Engine, _parent)
{
		mesh = std::shared_ptr<Mesh>(_mesh);
		material = std::shared_ptr<Material>(_material);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void MeshRenderer::Update()
{
	glUseProgram(material->Program);
	// Send this through the material instead
	// That way the material can handle all data as needed
	// since diffuse, bump etc will all subclass material.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mesh->Vertices), &mesh->Vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mesh->Triangles), &mesh->Triangles, GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLES, mesh->Triangles.size(), GL_UNSIGNED_INT, 0);
}

void MeshRenderer::LateUpdate()
{
}