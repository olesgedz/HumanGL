#include "42run.h"

void		replace_light(Engine* eng)
{
	if (eng->state->next == forw)
		eng->state->prev_light->move_to(eng->state->plat_start[0] + 15.0f, 2.0f, eng->state->plat_start[2]);
	else if (eng->state->next == right)
		eng->state->prev_light->move_to(eng->state->plat_start[0], 2.0f, eng->state->plat_start[2] + 15.0f);
	else if (eng->state->next == left)
		eng->state->prev_light->move_to(eng->state->plat_start[0], 2.0f, eng->state->plat_start[2] - 15.0f);
	Entity* ptr = eng->state->prev_light;
	eng->state->prev_light = eng->state->current_light;
	eng->state->current_light = eng->state->next_light;
	eng->state->next_light = ptr;
}

static void	replace_obst(Engine* eng)
{
	int raw;
	int line = 5;

	for (int i = 0; i < 6; ++i)
	{
		raw = rand() % 3 - 1;
		line += rand() % 4 + 2;
		if (eng->state->next == forw)
			eng->state->obst1[i]->move_to(eng->state->plat_end[0] + line, -1.0f, eng->state->plat_end[2] + raw);
		else if (eng->state->next == right)
			eng->state->obst1[i]->move_to(eng->state->plat_end[0] + raw, -1.0f, eng->state->plat_end[2] + line);
		else
			eng->state->obst1[i]->move_to(eng->state->plat_end[0] + raw, -1.0f, eng->state->plat_end[2] - line);
	}
	Entity** ptr = eng->state->obst1;
	eng->state->obst1 = eng->state->obst2;
	eng->state->obst2 = ptr;
}

static void	replace_coins(Engine* eng)
{
	int raw;
	int line = 6;

	for (int i = 0; i < 6; ++i)
	{
		raw = rand() % 3 - 1;
		line += rand() % 3 + 1;
		if (eng->state->next == forw)
			eng->state->coins1[i]->move_to(eng->state->plat_end[0] + line, -0.5f, eng->state->plat_end[2] + raw);
		else if (eng->state->next == right)
			eng->state->coins1[i]->move_to(eng->state->plat_end[0] + raw, -0.5f, eng->state->plat_end[2] + line);
		else
			eng->state->coins1[i]->move_to(eng->state->plat_end[0] + raw, -0.5f, eng->state->plat_end[2] - line);
		for (int j = 0; j < 6; ++j)
		{
			if (eng->state->coins1[i]->position.x == eng->state->obst2[j]->position.x && eng->state->coins1[i]->position.z == eng->state->obst2[j]->position.z)
				eng->state->coins1[i]->move(.0f, 1.0f, 0.0f);
		}
	}
	Entity** ptr = eng->state->coins1;
	eng->state->coins1 = eng->state->coins2;
	eng->state->coins2 = ptr;
}

void		replace_platform(Engine* eng)
{
	int				i;
	int				j;
	unsigned int	k;
	Entity** ptr;

	k = 0;
	replace_obst(eng);
	replace_coins(eng);
	if (eng->state->next == forw)
	{
		for (i = -1; i < 29; ++i)
			for (j = -1; j < 2; ++j)
				eng->state->current_plat[k++]->move_to((float)i + eng->state->plat_end[0], -1.05f, (float)j + eng->state->plat_end[2]);
		eng->state->plat_end[0] += 29.0f;
	}
	else if (eng->state->next == right)
	{
		for (i = -1; i < 29; ++i)
			for (j = -1; j < 2; ++j)
				eng->state->current_plat[k++]->move_to((float)j + eng->state->plat_end[0], -1.05f, (float)i + eng->state->plat_end[2]);
		eng->state->plat_end[2] += 29.0f;
	}
	else
	{
		for (i = -1; i < 29; ++i)
			for (j = -1; j < 2; ++j)
				eng->state->current_plat[k++]->move_to((float)j + eng->state->plat_end[0], -1.05f, eng->state->plat_end[2] - (float)i);
		eng->state->plat_end[2] -= 29.0f;
	}
	ptr = eng->state->current_plat;
	eng->state->current_plat = eng->state->next_plat;
	eng->state->next_plat = ptr;
}