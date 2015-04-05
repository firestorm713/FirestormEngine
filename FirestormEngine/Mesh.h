// contains vectors for the following things:
// 
// Vector<glm::vec3> Vertices
// Vector<int> Triangles
// Vector<glm::vec3> Normals
// Vector<glm::vec2> UVs
// 
// This class is only for handling the raw geometry.
// MeshRenderer actually draws the object.
//
#pragma once
#include<vector>
#include<glm\glm.hpp>
#include<string>

class Mesh
{
public:
	std::vector<glm::vec3> Vertices;
	std::vector<int> Triangles;
	std::vector<glm::vec3> Normals;
	std::vector<glm::vec2> UVs;

	Mesh(std::vector<glm::vec3> _vertices, std::vector<int> _triangles);
	Mesh(std::vector<glm::vec3> _vertices, std::vector<int> _triangles, std::vector<glm::vec3> _normals, std::vector<glm::vec2>UVs);
	~Mesh();
	void LoadFromFile(std::string path);
	void RecalculateNormals();
};