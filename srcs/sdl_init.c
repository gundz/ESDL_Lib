#include <easy_sdl.h>
#include <SDL.h>
#include <string.h>
#include <stdio.h>

static void				get_screen_resolution(int *rx, int *ry)
{
	*rx = RX;
	*ry = RY;
}

static void				init_esdl(t_esdl *esdl)
{
	get_screen_resolution(&esdl->en.rx, &esdl->en.ry);

	memset(&esdl->en.in, 0, sizeof(t_input));

	esdl->fps.current = 0;
	esdl->fps.fps = 0;
	esdl->fps.update = 0;
	esdl->run = 1;

	fps_limit(esdl);
}

int					init_sdl(t_esdl *esdl)
{
	int				ret;

	init_esdl(esdl);
	ret = 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ret = -1;
		printf("%s\n", SDL_GetError());
	}

	esdl->en.win = SDL_CreateWindow(NAME, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, RX, RY, SDL_WINDOW_SHOWN);
	if (!esdl->en.win)
	{
		ret = -1;
		printf("%s\n", SDL_GetError());
	}

	esdl->en.ren = SDL_CreateRenderer(esdl->en.win, -1,
			SDL_RENDERER_ACCELERATED);
	if (!esdl->en.ren)
	{
		ret = -1;
		printf("%s\n", SDL_GetError());
	}
	return (ret);
}

void				quit_sdl(t_esdl *esdl)
{
    SDL_DestroyRenderer(esdl->en.ren);
	SDL_DestroyWindow(esdl->en.win);
	SDL_Quit();
}