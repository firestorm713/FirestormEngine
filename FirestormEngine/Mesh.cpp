#include"Mesh.h"

Mesh::Mesh(std::vector<glm::vec3> _vertices, std::vector<int> _triangles)
{
	Vertices = _vertices;
	Triangles = _triangles;
	for(int i = 0; i < Vertices.size(); i++)
	{
		UVs.push_back(glm::vec2(0,0));
	}
	RecalculateNormals();
}

Mesh::~Mesh()
{
}

Mesh::Mesh(std::vector<glm::vec3> _vertices, std::vector<int> _triangles, std::vector<glm::vec3> _normals, std::vector<glm::vec2> _UVs)
{
	Vertices = _vertices;
	Triangles = _triangles;
	Normals = _normals;
	UVs = _UVs;
}

void Mesh::LoadFromFile(std::string path)
{
}

void Mesh::RecalculateNormals()
{
}