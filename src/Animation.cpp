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

vec3 Animation::GetPosition(const Entity& entity, float time)
{
	if (keys.size() == 1)
		return keys[0]->position;
	int startFrame = FindKey();
	int endFrame =  startFrame >= keys.size() ? 0 : startFrame + 1;

	float DeltaTime = keys[endFrame]->startTime - keys[startFrame]->startTime;
	float Factor = (timeFromStart - keys[startFrame]->startTime) / DeltaTime;
//
//
//	vec3 vecDiff = keys[endFrame]->rotation - keys[startFrame]->rotation;
////
////
//	vec3 r =  keys[startFrame]->position + vecDiff  * Factor;
	vec3 r = lerp(keys[startFrame]->position, keys[endFrame]->position, Factor);

	return r;
}

int Animation::FindKey()
{
//	float time = timeFromStart ;
//	int i = 0;
//	for (; (time < duration) && (i < keys.size()); )
//	{
//		time += keys[i]->frameTime;
//		if (time > duration)
//			break;
//		i++;
//	}
//		if (i > keys.size())
//			i-= 1;
	for (int i = 0; i < keys.size() - 1; i++)
	{
		if (timeFromStart < (float) keys[i + 1]->startTime)
			return i;
	}
	return 0 ;
}

vec3 Animation::GetRotationMatrix(const Entity& entity, float time)
{
	if (keys.size() == 1)
		return keys[0]->rotation;
	int startFrame = FindKey();
	std::cout << "Frame " << startFrame << std::endl;
	int endFrame =  startFrame >= keys.size() ? 0 : startFrame + 1;

 	float DeltaTime = keys[endFrame]->startTime - keys[startFrame]->startTime;
	float Factor = (timeFromStart - keys[startFrame]->startTime) / DeltaTime;
//
//
//	vec3 vecDiff = keys[endFrame]->rotation - keys[startFrame]->rotation;
////
////
//	vec3 r =  keys[startFrame]->rotation + vecDiff  * Factor;
 vec3 r = lerp(keys[startFrame]->rotation, keys[endFrame]->rotation, Factor);

//	vec3 r =  keys[startFrame]->rotation + ((keys[endFrame]->rotation - keys[startFrame]->rotation) * (1 / (keys[endFrame]->startTime - keys[startFrame]->startTime))) * (timeFromStart - keys[startFrame]->startTime);
//	std::cout << r.x << " " << r.y << " "  << r.z << " "   << std::endl;
//	yp = y0 + ((y1-y0)/(x1-x0)) * (xp - x0);
	return r;
}

mat4 Animation::GetAnimationMatrix(const Entity& entity, float time)
{
	timeFromStart += time;

	if (timeFromStart >= duration)
		timeFromStart = 0;
	std::cout << timeFromStart << std::endl;
	std::cout << "Duration" << duration << std::endl;


	mat4 result = mat4(1.0f);
	result = rotate(result, GetRotationMatrix(entity, time));
	result = translate(result, GetPosition(entity, time));

	return result;
}

void Animation::AddAnimationKey(AnimationKey *key)
{
		key->startTime = duration;
		keys.emplace_back(key);
		duration += key->frameTime;

}

Animation::Animation()
{

}

//Animation::Animation(const std::vector<AnimationKey> &keys) : keys(keys)
//{
//
//}
