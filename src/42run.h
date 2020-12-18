#pragma once
#include "engine.h"
#include <iostream>

#define WIDTH 640
#define HEIGHT 480

enum next_dir
{
	forw,
	left,
	right
};

enum player_pos
{
	left_r,
	center_r,
	right_r
};

struct state
{
	float		plat_end[3];
	float		plat_start[3];
	Entity		**current_plat;
	Entity		**next_plat;
	Entity		*current_light;
	Entity		*next_light;
	Entity		*prev_light;
	Entity		**obst1;
	Entity		**obst2;
	Entity		**coins1;
	Entity		**coins2;
	bool		rotate;
	float		frames;
	next_dir	current;
	next_dir	w_current;
	next_dir	next;
	player_pos	p_pos;
	float		shifting_x;
	float		shifting_y;
	int			shift;
	bool		shifting;
	bool		shift_rotate;
	int			delay;
	bool		jump;
	float		jump_time;
	bool		game_over;
	int			coins;
	double		timer_s;
};

void	init_game(Engine* eng, state* state);
void	init_data(Engine* eng, state* state);
void	game_loop(Engine* eng);
void	controls(Engine* eng);
void	shift_player_l(Engine* eng);
void	shift_player_r(Engine* eng);
void	replace_platform(Engine* eng);
void	replace_light(Engine* eng);
void	detect_collision(Engine* eng);