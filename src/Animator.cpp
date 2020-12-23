//
// Created by Jeromy Black on 12/19/20.
//

#include "Animator.h"

Animator::Animator()
{
	for (int i = 0; i < 10; ++i)
		animations["idle"].emplace_back();
	for (int i = 0; i < 10; ++i)
		animations["run"].emplace_back();
	for (int i = 0; i < 10; ++i)
		animations["jump"].emplace_back();

	// idle anim
	for (int i = 0; i < 10; ++i)
	{
		animations["idle"][i].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
		animations["idle"][i].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	}
	// run anim
	// torso
	animations["run"][0].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(10, 0, 0), vec3(1, 1, 1)));
	animations["run"][0].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(10, 10, 0), vec3(1, 1, 1)));
	animations["run"][0].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(10, -10, 0), vec3(1, 1, 1)));
	animations["run"][0].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(10, 0, 0), vec3(1, 1, 1)));

	// head
	animations["run"][1].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["run"][1].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, -10, 10), vec3(1, 1, 1)));
	animations["run"][1].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 10, -10), vec3(1, 1, 1)));
	animations["run"][1].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	//arm 1
	animations["run"][2].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, -70), vec3(1, 1, 1)));
	animations["run"][2].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(45, -10, -70), vec3(1, 1, 1)));
	animations["run"][2].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(-45, 10, -70), vec3(1, 1, 1)));
	animations["run"][2].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, -70), vec3(1, 1, 1)));

	animations["run"][3].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, -90, 0), vec3(1, 1, 1)));
	animations["run"][3].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, -110, 0), vec3(1, 1, 1)));
	animations["run"][3].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, -70, 0), vec3(1, 1, 1)));
	animations["run"][3].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, -90, 0), vec3(1, 1, 1)));

	//arm 2
	animations["run"][4].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 70), vec3(1, 1, 1)));
	animations["run"][4].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(-45, -10, 70), vec3(1, 1, 1)));
	animations["run"][4].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(45, 10, 70), vec3(1, 1, 1)));
	animations["run"][4].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 70), vec3(1, 1, 1)));

	animations["run"][5].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 90, 0), vec3(1, 1, 1)));
	animations["run"][5].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, 110, 0), vec3(1, 1, 1)));
	animations["run"][5].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 70, 0), vec3(1, 1, 1)));
	animations["run"][5].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 90, 0), vec3(1, 1, 1)));

	//leg 1
	animations["run"][6].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["run"][6].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(45, -10, 0), vec3(1, 1, 1)));
	animations["run"][6].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(-45, 10, 0), vec3(1, 1, 1)));
	animations["run"][6].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	animations["run"][7].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(15, 0, 0), vec3(1, 1, 1)));
	animations["run"][7].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(60, 0, 0), vec3(1, 1, 1)));
	animations["run"][7].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["run"][7].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(15, 0, 0), vec3(1, 1, 1)));

	//leg 2
	animations["run"][8].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["run"][8].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(-45, -10, 0), vec3(1, 1, 1)));
	animations["run"][8].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(45, 10, 0), vec3(1, 1, 1)));
	animations["run"][8].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	animations["run"][9].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(15, 0, 0), vec3(1, 1, 1)));
	animations["run"][9].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["run"][9].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(60, 0, 0), vec3(1, 1, 1)));
	animations["run"][9].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(15, 0, 0), vec3(1, 1, 1)));

	// jump anim
	// torso
	animations["jump"][0].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][0].AddAnimationKey(new AnimationKey(2.5f, vec3(0, -0.15f, 0), vec3(10, 0, 0), vec3(1, 1, 1)));
	animations["jump"][0].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 1.0f, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][0].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	// head
	animations["jump"][1].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][1].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][1].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][1].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	// arm 1
	animations["jump"][2].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, -85), vec3(1, 1, 1)));
	animations["jump"][2].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, -75), vec3(1, 1, 1)));
	animations["jump"][2].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, -75), vec3(1, 1, 1)));
	animations["jump"][2].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, -85), vec3(1, 1, 1)));
	animations["jump"][2].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, -85), vec3(1, 1, 1)));

	animations["jump"][3].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][3].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, -90, 0), vec3(1, 1, 1)));
	animations["jump"][3].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, -90, 0), vec3(1, 1, 1)));
	animations["jump"][3].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][3].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	// arm 2
	animations["jump"][4].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 85), vec3(1, 1, 1)));
	animations["jump"][4].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 75), vec3(1, 1, 1)));
	animations["jump"][4].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 75), vec3(1, 1, 1)));
	animations["jump"][4].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 85), vec3(1, 1, 1)));
	animations["jump"][4].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 85), vec3(1, 1, 1)));

	animations["jump"][5].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][5].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 90, 0), vec3(1, 1, 1)));
	animations["jump"][5].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 90, 0), vec3(1, 1, 1)));
	animations["jump"][5].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][5].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	// leg 1
	animations["jump"][6].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][6].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(-30, 0, 0), vec3(1, 1, 1)));
	animations["jump"][6].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][6].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	
	animations["jump"][7].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][7].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(30, 0, 0), vec3(1, 1, 1)));
	animations["jump"][7].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][7].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	// leg 2
	animations["jump"][8].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][8].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(-30, 0, 0), vec3(1, 1, 1)));
	animations["jump"][8].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][8].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));

	animations["jump"][9].AddAnimationKey(new AnimationKey(5.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][9].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(30, 0, 0), vec3(1, 1, 1)));
	animations["jump"][9].AddAnimationKey(new AnimationKey(2.5f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
	animations["jump"][9].AddAnimationKey(new AnimationKey(0.0f, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1)));
}