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
	void	    draw_scene(Animator * animator, Scene* scene, Camera* cam);
	void	    draw_pbr(Scene *scene, Camera *cam);
	void    	draw_skybox(Skybox *skybox, Camera* cam);
    void        draw_child(Entity* ent, Animator *animator,  Scene *scene, Camera *cam, mat4 par_model);
	std::string animation_key;
	float       scaler = 1.0f;
private:
	mat4	projection;


};
