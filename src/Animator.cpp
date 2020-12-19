//
// Created by Jeromy Black on 12/19/20.
//

#include "Animator.h"

Animator::Animator()
{
	animations.emplace_back(5.0f);
	animations[0].duration = 16;
	animations[0].keys.emplace_back(new AnimationKey(0, vec3(0,0,0) , vec3(0,0,0),vec3(0,0,0)));
	animations[0].keys.emplace_back(new AnimationKey(3.0f,vec3(0,0,0), vec3(30,0,0), vec3(0,0,0)));



//	AnimationKey l1(3.0f,mat4(1), rotation, mat4(1));
//	animations.at(0).keys.push_back(l1);
}