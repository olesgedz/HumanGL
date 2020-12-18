#ifndef MODEL_HPP
#define MODEL_HPP
#include "vox.hpp"
#include <vector>

class Model {
 public:
  Model(const std::vector<GLfloat> &vertexPositions,
		const std::vector<GLfloat> &textureCoord,
		const std::vector<GLuint> &indices);
  ~Model();
  void bind() const;
  void unbind() const;
  GLuint getIndicesCount() const;
 private:
  std::vector<GLuint> m_buffers;
  GLuint m_vao = 0;
  GLuint m_vboCount = 0;
  GLuint m_indicesCount = 0;
  void addVBO(int dim, const std::vector<GLfloat> &data);
  void addEBO(const  std::vector<GLuint> &indices);
};
#endif