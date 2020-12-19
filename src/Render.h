#pragma once
#include "scene.h"
#include "camera.h"
#include "skybox.h"
#include "Animator.h"
class Render
{
public:
	Entity *player;
public:
	void	init();
	void	draw_scene(Animator * animator, Scene* scene, Camera* cam);
	void	draw_pbr(Scene *scene, Camera *cam);
	void	draw_skybox(Skybox *skybox, Camera* cam);

private:
	mat4	projection;
	glm::mat4	ortProjection;

};
