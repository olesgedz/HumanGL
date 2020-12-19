//
// Created by Jeromy Black on 12/19/20.
//

#include "Animation.h"
#include "glad.h"
#include "GLFW/glfw3.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Maths.h"
#include <iostream>

vec3 Animation::GetAnimationTransform(const Entity& entity, float time)
{
//	vec3 ret = mat4(1.0f);
//	return rotate(ret, vec3(0, (float)glfwGetTime() * 30, 0));
	return vec3(1.0f, 1,1);
}

vec3 Animation::GetRotationMatrix(const Entity& entity, float time)
{
	if (keys.size() == 1)
		return keys[0]->rotation;

 	float DeltaTime = keys[1]->frameTime - keys[0]->frameTime;
	float Factor = (timeFromStart - keys[0]->frameTime) / DeltaTime;


	vec3 vecDiff = keys[1]->rotation - keys[0]->rotation;


	vec3 r =  keys[0]->rotation + vecDiff  * Factor;
	std::cout << r.x << " " << r.y << " "  << r.z << " "   << std::endl;
	return r;
}

mat4 Animation::GetAnimationMatrix(const Entity& entity, float time)
{
	timeFromStart += time;

	if (timeFromStart > duration)
		timeFromStart = 0;
	std::cout << timeFromStart << std::endl;

	mat4 result = mat4(1.0f);
	result = rotate(result, GetRotationMatrix(entity, time));
	vec3 a = vec3(entity.position.x,entity.position.y,entity.position.z);
	result =   translate(result, a);
	return result;
}

//Animation::Animation(const std::vector<AnimationKey> &keys) : keys(keys)
//{
//
//}

Animation::Animation(float duration)
{

}
