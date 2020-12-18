//
// Created by Oles Gedz on 23/06/2020.
//

#include "Camera.hpp"
#include "vox.hpp"
#include "openglInputs.hpp"
#include "Display.hpp"
#include "Events.hpp"

void Camera::input(float delta) {
  glm::vec3 change = glm::vec3(0.f);
  float speed = 2;
  if (glfwGetKey(Display::getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
	change.x -= cos(glm::radians(rotation.y + 90)) * speed;
	change.z -= sin(glm::radians(rotation.y + 90)) * speed;
  }
  if (glfwGetKey(Display::getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
	change.x += cos(glm::radians(rotation.y + 90)) * speed;
	change.z += sin(glm::radians(rotation.y + 90)) * speed;
  }
  if (glfwGetKey(Display::getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
	change.x -= cos(glm::radians(rotation.y)) * speed;
	change.z -= sin(glm::radians(rotation.y)) * speed;
  }
  if (glfwGetKey(Display::getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
	change.x += cos(glm::radians(rotation.y)) * speed;
	change.z += sin(glm::radians(rotation.y)) * speed;
  }
  position += change * delta;

  rotation += glm::vec3(Events::yoffset, Events::xoffset, 0);
  Events::xoffset = 0;
  Events::yoffset = 0;

  if (rotation.x > 80) {
	rotation.x = 90;
  } else if (rotation.x < -80) {
	rotation.x = -80;
  }
  if (rotation.y < 0) {
	rotation.y = 360;
  } else if (rotation.y > 360) {
	rotation.y = 0;
	int centerX = Display::SCR_WIDTH / 2;
	int centerY = Display::SCR_HEIGHT / 2;
  }
}
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//  static float lastX = xpos;
//  static float lastY = ypos;
//
//  float xoffset = xpos - lastX;
//  float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//
//  lastX = xpos;
//  lastY = ypos;
//}
//  void Camera::mouseInput(GLFWwindow *window, double xpos, double ypos) {
//
//	static float lastX = xpos;
//	static float lastY = ypos;
//
//	CameraVar::xoffset = xpos - lastX;
//	CameraVar::yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//
//	lastX = xpos;
//	lastY = ypos;
//
//  }
