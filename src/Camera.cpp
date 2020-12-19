#include "camera.h"

Camera::Camera()
{
	pos = glm::vec3(-1.0f, 0.0f, 5.0f);
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	direction = glm::normalize(pos - target);
	glm::vec3 temp_up = glm::vec3(0.0f, 1.0f, 0.0f);
	right = glm::normalize(glm::cross(temp_up, direction));
	up = glm::cross(direction,right);
	view = glm::lookAt(pos, pos + front, up);
	yaw = -90.0f;
	pitch = 0.0f;
	speed = 0.5f;
}

void Camera::update_free()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	view = glm::lookAt(pos, pos + front, up);
}

void Camera::update_follow(glm::vec3 targ)
{
	pos.x = targ.x - cos(glm::radians(yaw)) * 3;
	pos.z = targ.z - sin(glm::radians(yaw)) * 3;
	direction = glm::normalize(pos - targ);
	glm::vec3 temp_up = glm::vec3(0.0f, 1.0f, 0.0f);
	right = glm::normalize(glm::cross(temp_up, direction));
	up = glm::cross(direction, right);
	view = glm::lookAt(pos, targ, up);
}