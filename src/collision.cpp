#include "42run.h"

void	detect_collision(Engine* eng)
{
	for (int i = 0; i < 6; ++i)
	{
		if (abs(eng->player->position.x - eng->state->obst1[i]->position.x) < 0.5f && abs(eng->player->position.z - eng->state->obst1[i]->position.z) < 0.5f)
		{
			if (eng->free_cam)
				return ;
			if (eng->player->position.y < -0.05f)
				eng->state->game_over = true;
		}
		if (abs(eng->player->position.x - eng->state->coins1[i]->position.x) < 0.5f && abs(eng->player->position.y - eng->state->coins1[i]->position.y) < 0.6f
			&& abs(eng->player->position.z - eng->state->coins1[i]->position.z) < 0.5f)
		{
			eng->state->coins++;
			eng->state->coins1[i]->move_to(-1.0f, -0.5f, -1.0f);
		}
	}
}
