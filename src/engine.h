#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "render.h"
#include "events.h"
#include "skybox.h"

struct state;

class Engine {
public:
	Camera						cam;
	double						delta_time = 0.0;
	std::vector<Model *>		models;
	std::vector<Entity *>		scene;
	Controls					controls;
	Skybox						skybox;
	Entity						*player;
	std::vector<Entity *>		light_sources;
	glm::vec3					**light_pos;
	bool						free_cam;
	bool						close_eng;

public:
			~Engine();
	void	init_engine(int width, int height);
	void	run_engine();
	void	add_model(Model *mod);
	void	add_entity(Entity *ent);
	void	set_player(Entity *ent);
	void	add_light_source(Entity *ent);
	void	set_lights_pos();
	void	add_text_ui(std::string str, float x, float y, float scale);
	void	change_text(std::string str, int id);
private:
	GLFWwindow				*window;
	Render					rend;
	double					old_time = 0.0;
	double					timer = 0.0;
	int						fps = 0;
};
