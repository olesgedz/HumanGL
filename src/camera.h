#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	glm::vec3	pos;
	glm::vec3	front;
	glm::vec3	target;
	glm::vec3	direction;
	glm::vec3	right;
	glm::vec3	up;
	glm::mat4	view;
	float		speed;
	float		yaw;
	float		pitch;
public:
	Camera();
	void	update_free();
	void	update_follow(glm::vec3 targ);
private:

};
