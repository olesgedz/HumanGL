#include "Model.hpp"
#include <vector>

Model::Model(const std::vector<GLfloat> &vertexPositions,
             const std::vector<GLfloat> &textureCoord,
			 const std::vector<GLuint> &indices)
			 : m_indicesCount(indices.size())
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    // glGenBuffers(1, &m_vertexId);
    // glBindBuffer(GL_ARRAY_BUFFER, m_vertexId);
    // glBufferData(GL_ARRAY_BUFFER, vertexPositions.size() * sizeof(vertexPositions[0]),
    // vertexPositions.data(), GL_STATIC_DRAW);
    // glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    // glEnableVertexAttribArray(0);
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    addVBO(3, vertexPositions);
    addVBO(2, textureCoord);
    addEBO(indices);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}
void Model::addVBO(int dim, const std::vector<GLfloat> &data)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                data.size() * sizeof(data[0]),
                data.data(),
                GL_STATIC_DRAW);
    glVertexAttribPointer(m_vboCount,
                        dim,
                        GL_FLOAT,
                        GL_FALSE,
                        0,
                        (GLvoid *)0);
    glEnableVertexAttribArray(m_vboCount++);
    m_buffers.push_back(vbo);
}
void Model::bind() const
{
    glBindVertexArray(m_vao);
}

Model::~Model()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(m_buffers.size(), m_buffers.data()); 
}

void Model::unbind() const
{
    glBindVertexArray(0);
}

void Model::addEBO(const std::vector<GLuint> &indices)
{
	GLuint  ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		indices.size() * sizeof(indices[0]),
		indices.data(),
		GL_STATIC_DRAW);
	m_buffers.push_back(ebo);

}

GLuint Model::getIndicesCount() const {
  return m_indicesCount;
}
