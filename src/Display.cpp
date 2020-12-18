#include "vox.hpp"
#include "openglInputs.hpp"
#include "Display.hpp"
#include <memory>
#include "shader.h"
#include "Events.hpp"
#include "Camera.hpp"

	//std::unique_ptr<GLFWwindow> window;

namespace Display
{
	std::unique_ptr<GLFWwindow, DestroyglfwWin> window;

    bool isOpen = true;

	void  init()
	{
	  	//glfwSetErrorCallback(glfw_error_callback);
		glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		window.reset(glfwCreateWindow(Display::SCR_WIDTH, Display::SCR_HEIGHT, "ft_vox", NULL, NULL));

		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return ;
		}
		glfwMakeContextCurrent(window.get());
		glfwSetFramebufferSizeCallback(window.get(), Events::framebuffer_size_callback);
		glfwSetCursorPosCallback(window.get(), Events::mouse_callback);
		glfwSetScrollCallback(window.get(), Events::scroll_callback);
		glfwSwapInterval(1);
		// tell GLFW to capture our mouse
		glfwSetInputMode(window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetInputMode(window.get(), GLFW_STICKY_KEYS,GLFW_TRUE);
		// ---------------------------------------
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return ;
		}
		GLint flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			//glDebugMessageCallback(glDebugOutput, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}
	}
	
	void update()
	{
		isOpen = !glfwWindowShouldClose(window.get());
	  Events::processInput(window.get());
		glfwSwapBuffers(window.get());
		glfwPollEvents();
		//
	}

	void clear()
	{
		glClearColor(0.4, 0.4, 0.3, 1.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void close()
	{

	}
	GLFWwindow * getWindow()
	{
		return (Display::window.get());
	}
	
}