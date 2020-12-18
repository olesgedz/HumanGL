//
// Created by Oles Gedz on 11/06/2020.
//
#include <vector>
#include <Renderer/Quad.hpp>
std::vector<GLfloat> vertexPositions =
	{
		0.5, 	0.5,  	0,
	 	-0.5, 	0.5,  	0,
	 	-0.5, 	-0.5, 	0,
	 	0.5,  	-0.5, 	0
	};
std::vector<GLfloat> textureCoords =
	{
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,
		1.0, 0.0,
	};
std::vector <GLuint> indices =
	{
		0, 1, 2,
		2, 3, 0
	};
Quad::Quad()
: m_model(vertexPositions, textureCoords, indices)
{

}

const Model& Quad::getModel() const
{
  return m_model;
}


