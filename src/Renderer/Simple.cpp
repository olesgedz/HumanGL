//
// Created by Oles Gedz on 05/06/2020.
//

#include "Renderer/Simple.hpp"
#include "Model.hpp"
#include "Renderer/Quad.hpp"
#include "Matrix.hpp"
void Renderer::Simple::draw(Quad &quad) {
    m_quads.push_back(&quad);
}

void Renderer::Simple::update(const Camera& camera)
{
	m_shader.bind();
	//time
	m_shader.setViewMatrix(Matrix::createViewMatrix(camera));
	for (auto& quad : m_quads)
	{
	  prepare(*quad);
	  glDrawElements(GL_TRIANGLES, quad->getModel().getIndicesCount(),
					 GL_UNSIGNED_INT, nullptr);
	}
	m_quads.clear();
}

void Renderer::Simple::prepare(Quad &quad)
{
 	 quad.getModel().bind();
 	 m_shader.setModelMatrix(Matrix::createModelMatrix(quad));
}
