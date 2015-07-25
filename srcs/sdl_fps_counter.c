#include <easy_sdl.h>

#include <stdio.h>

void			fps_counter(t_esdl *esdl)
{
	if ((esdl->fps.update = SDL_GetTicks()) - esdl->fps.current >= 1000)
	{
		esdl->fps.current = esdl->fps.update;
		sprintf(esdl->fps.title, "%d fps", esdl->fps.fps);
		SDL_SetWindowTitle(esdl->en.win, esdl->fps.title);
		esdl->fps.fps = 0;
	}
	esdl->fps.fps++;
}

static void			fps_limit_delay(const unsigned int frameLimit)
{
	unsigned int	ticks = SDL_GetTicks();

	if (frameLimit < ticks)
		return ;
	if (frameLimit > ticks + MAX_FPS_VAL)
		SDL_Delay(MAX_FPS_VAL);
	else
		SDL_Delay(frameLimit - ticks);
}

void				fps_limit(t_esdl *esdl)
{
	fps_limit_delay(esdl->fps.frameLimit);
	esdl->fps.frameLimit = SDL_GetTicks() + MAX_FPS_VAL;
}