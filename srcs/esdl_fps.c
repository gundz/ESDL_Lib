#include <easy_sdl.h>

#include <stdio.h>

void				Esdl_fps_counter(t_esdl *esdl)
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

static void			Esdl_fps_limit_delay(t_esdl *esdl, const unsigned int frameLimit)
{
	unsigned int	ticks = SDL_GetTicks();
	int				max = (1000 / esdl->fps.limit);

	if (frameLimit < ticks)
		return ;
	if (frameLimit > ticks + max)
		SDL_Delay(max);
	else
		SDL_Delay(frameLimit - ticks);
}

void				Esdl_fps_limit(t_esdl *esdl)
{
	Esdl_fps_limit_delay(esdl, esdl->fps.frameLimit);
	esdl->fps.frameLimit = SDL_GetTicks() + (1000 / esdl->fps.limit);
}