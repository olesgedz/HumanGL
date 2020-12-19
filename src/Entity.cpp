#include "entity.h"
#include "glm/glm.hpp"

Entity::Entity()
{
	move_to(0.0f, 0.0f, 0.0f);
	scale(1.0f, 1.0f, 1.0f);
	set_color(1.0f, 1.0f, 1.0f);
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
	position.x += x;
	position.y += y;
	position.z += z;
}

void Entity::move_to(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void Entity::rotate(float x, float y, float z)
{
	angle.x += x;
	angle.y += y;
	angle.z += z;
}

void Entity::rotate_to(float x, float y, float z)
{
	angle.x = x;
	angle.y = y;
	angle.z = z;
}

void Entity::scale(float x, float y, float z)
{
	e_scale.x = x;
	e_scale.y = y;
	e_scale.z = z;
}

void Entity::set_color(float r, float g, float b)
{
    color.x = r;
    color.y = g;
    color.z = b;
}