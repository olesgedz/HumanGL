//
// Created by Oles Gedz on 23/06/2020.
//

#include "Events.hpp"


float Events::xoffset = 0;
float Events::yoffset = 0;

static void glfw_error_callback(int error, const char *description)
{
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


void Events::processInput(GLFWwindow *window)
{
  static float lastpress;

  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void Events::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  // make sure the viewport matches the new window dimensions; note that width and
  // height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------

void Events::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

void Events::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
  static float lastX = xpos;
  static float lastY = ypos;

 xoffset = xpos - lastX;
 yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

  lastX = xpos;
  lastY = ypos;
}