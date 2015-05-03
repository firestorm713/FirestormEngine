#include"Mesh.h"

Mesh::Mesh(std::vector<glm::vec3> _vertices, std::vector<int> _triangles, std::vector<glm::vec2> _UVs)
{
	Vertices = _vertices;
	Triangles = _triangles;
	UVs = _UVs;
}

Mesh::~Mesh()
{
}

void Mesh::LoadFromFile(std::string path)
{
}

void Mesh::RecalculateNormals()
{
}