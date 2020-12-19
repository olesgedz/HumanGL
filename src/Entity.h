#pragma once
#include "model.h"
#include "Maths.h"
#include "glm/glm.hpp"

class Entity
{
public:
	Model	*mod;
	vec3	position;
	vec3	e_scale;
	vec3	angle;
	vec3    color;
public:
	Entity();
	void			set_model(Model *mod);
	void			move(float x, float y, float z);
	void			move_to(float x, float y, float z);
	void			rotate(float x, float y, float z);
	void			rotate_to(float x, float y, float z);
	void			scale(float x, float y, float z);
	virtual void	update();
    void            set_color(float r, float g, float b);
private:
};
