#pragma once
#include "model.h"
#include "glm/glm.hpp"

class Entity
{
public:
	Model		*mod;
	glm::vec3	position;
	glm::vec3	e_scale;
	glm::vec3	angle;
public:
	Entity();
	void set_model(Model *mod);
	void move(float x, float y, float z);
	void move_to(float x, float y, float z);
	void rotate(float x, float y, float z);
	void rotate_to(float x, float y, float z);
	void scale(float x, float y, float z);
private:
};
