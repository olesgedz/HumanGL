//
// Created by Oles Gedz on 23/06/2020.
//

#include "Matrix.hpp"
#include "Display.hpp"
#include "Camera.hpp"
namespace Matrix {


glm::mat4 createViewMatrix(const Camera& entity)
{
  glm::mat4 matrix = glm::identity<glm::mat4>();

  matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), {1, 0, 0});
  matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), {0, 1, 0});
  matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), {0, 0, 1});

  matrix = glm::translate(matrix, -entity.position);

  return matrix;
}

glm::mat4 createModelMatrix(const Entity& entity)
{
  glm::mat4 matrix = glm::identity<glm::mat4>();

  matrix = glm::translate(matrix, entity.position);

  matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), {1, 0, 0});
  matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), {0, 1, 0});
  matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), {0, 0, 1});

  return matrix;
}

glm::mat4 createProjMatrix()
{
  return glm::perspective(glm::radians(120.0f),
						  (float)Display::SCR_WIDTH/ (float)Display::SCR_HEIGHT,
						  0.001f,
						  1000.0f);
}

}