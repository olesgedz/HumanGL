#include "entity.h"
#include "glm/glm.hpp"
int  Entity::idNumber = 0;
Entity::Entity()
{
	move_to(0.0f, 0.0f, 0.0f);
	angle[0] = 0.0f;
	angle[1] = 0.0f;
	angle[2] = 0.0f;
	scale(1.0f, 1.0f, 1.0f);
	set_color(1.0f, 1.0f, 1.0f);
	ID = idNumber;
	idNumber++;
}

void	Entity::update()
{

}

void Entity::set_model(Model *model)
{
	mod = model;
}

void Entity::move(float x, float y, float z)
{
	position[0] += x;
	position[1] += y;
	position[2] += z;
}

void Entity::move_to(float x, float y, float z)
{
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

void Entity::rotate(float x, float y, float z)
{
	angle[0] += x;
	angle[1] += y;
	angle[2] += z;
}

void Entity::rotate_to(float x, float y, float z)
{
	angle[0] = x;
	angle[1] = y;
	angle[2] = z;
}

void Entity::scale(float x, float y, float z)
{
	e_scale[0] = x;
	e_scale[1] = y;
	e_scale[2] = z;
}

void Entity::set_color(float r, float g, float b)
{
    color.x = r;
    color.y = g;
    color.z = b;
}