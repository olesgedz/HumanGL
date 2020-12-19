#include "engine.h"
#include "glad.h"
#include <iostream>
#include "glm/glm.hpp"


Engine::~Engine()
{
	int length = models.size();
	for (int i = 0; i < length; ++i)
	{
		delete models[i]->vertices;
		delete models[i];
	}
	length = scene.ents.size();
	for (int i = 0; i < length; ++i)
		delete scene.ents[i];
	std::cout << "Engine off" << std::endl;
}

void Engine::init_engine(int width, int height)
{
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, "42 run", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGL())
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetWindowUserPointer(window, &controls);
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	controls.yaw = cam.yaw;
	controls.pitch = cam.pitch;
	rend.init();
	std::vector<std::string> faces;
	faces.push_back("res/cubemaps/right.jpg");
	faces.push_back("res/cubemaps/left.jpg");
	faces.push_back("res/cubemaps/top.jpg");
	faces.push_back("res/cubemaps/bottom.jpg");
	faces.push_back("res/cubemaps/front.jpg");
	faces.push_back("res/cubemaps/back.jpg");
	skybox.init(faces);
	skybox.set_shader("res/shaders/skybox_vert.glsl", "res/shaders/skybox_frag.glsl");

}

void Engine::run_engine()
{
	old_time = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.3f, 0.4f, 0.9f, 1.0f);

		delta_time = glfwGetTime() - old_time;
		timer += delta_time;
		fps++;
		if (timer >= 1.0)
		{
			timer -= 1.0;
			std::cout << "fps - " << fps << std::endl;
			fps = 0;
		}
		old_time = glfwGetTime();

		cam.speed = 8.0f * delta_time;
		if (controls.keys[GLFW_KEY_W])
			cam.pos += cam.speed * cam.front;
		if (controls.keys[GLFW_KEY_S])
			cam.pos -= cam.speed * cam.front;
		if (controls.keys[GLFW_KEY_A])
			cam.pos -= cam.speed * glm::normalize(glm::cross(cam.front, cam.up));
		if (controls.keys[GLFW_KEY_D])
			cam.pos += cam.speed * glm::normalize(glm::cross(cam.front, cam.up));
		cam.yaw = controls.yaw;
		cam.pitch = controls.pitch;

		cam.update_free();
		rend.draw_skybox(&skybox, &cam);
		rend.draw_scene(&animator, &scene, &cam);
		//rend.draw_pbr(&scene, &cam);

		glfwSwapBuffers(window);
		glfwPollEvents();
		if(close_eng)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	glfwTerminate();
}

void Engine::add_model(Model *mod)
{
	models.push_back(mod);
}

void Engine::add_entity(Entity *ent)
{
	scene.add_entity(ent);
}

void Engine::set_player(Entity *ent)
{
	player = ent;
	rend.player = ent;
}

void Engine::add_light_source(glm::vec3 l_pos, glm::vec3 color)
{
	scene.add_light_source(l_pos, color);
}

