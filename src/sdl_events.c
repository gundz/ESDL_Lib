#include <easy_sdl.h>

#include <SDL.h>

#include <stdlib.h>


static int			check_input(SDL_Event *event, t_input *in)
{
	int				ret;

	ret = 0;
	if (event->type == SDL_KEYDOWN)
	{
		in->key[event->key.keysym.scancode] = 1;
		ret++;
	}
	else if (event->type == SDL_KEYUP)
	{
		in->key[event->key.keysym.scancode] = 0;
		ret++;
	}
	return (ret);
}

static int			check_mouse(SDL_Event *event, t_input *in)
{
	int				ret;

	ret = 0;
	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		in->button[event->button.button] = 1;
		ret++;
	}
	else if (event->type == SDL_MOUSEBUTTONUP)
	{
		in->button[event->button.button] = 0;
		ret++;
	}
	return (ret);
}

int					update_events(t_input *in, int *run)
{
	SDL_Event		event;
	int				ret;

	ret = 0;
	SDL_GetMouseState(&in->m_x, &in->m_y);
	SDL_GetRelativeMouseState(&in->m_r_x, &in->m_r_y);
	while (SDL_PollEvent(&event))
	{
		if ((ret += check_input(&event, in)) > 0)
			break ;
		if ((ret += check_mouse(&event, in)) > 0)
			break ;
		else if (event.type == SDL_QUIT)
			*run = 0;
	}
	return (ret);
}