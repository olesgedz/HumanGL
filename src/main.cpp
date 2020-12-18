#include "42run.h"
#include <time.h>

int		main(void)
{
	Engine	engine;
	
	srand(time(NULL));
	engine.init_engine(WIDTH, HEIGHT);
	engine.run_engine();
	delete(engine.state->current_plat);
	delete(engine.state->next_plat);
	delete(engine.state->obst1);
	delete(engine.state->obst2);
	return 0;
}
