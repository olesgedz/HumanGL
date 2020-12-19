#pragma once
#include "scene.h"
#include "camera.h"
#include "skybox.h"

class Render
{
public:
	Entity *player;
public:
	void	init();
	void	set_lights_pos(glm::vec3 **lights, int numb);
	void	draw_scene(Scene* scene, Camera* cam);
	void	draw_pbr(Scene *scene, Camera *cam);
	void	draw_skybox(Skybox *skybox, Camera* cam);

private:
	glm::mat4	projection;
	glm::mat4	ortProjection;
	vec3		light_pos[3];
};
