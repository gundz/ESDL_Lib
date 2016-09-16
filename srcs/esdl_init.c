/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:40:17 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 15:40:19 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>
#include <string.h>

static void			esdl_init_esdl(t_esdl *esdl)
{
	memset(&esdl->en.in, 0, sizeof(t_input));
	esdl->fps.current = 0;
	esdl->fps.fps = 0;
	esdl->fps.update = 0;
	esdl->run = 1;
	esdl->fps.framelimit = 0;
	esdl->fps.limit = MAX_FPS;
	esdl_fps_limit(esdl);
}

void				esdl_update_window_info(t_esdl *esdl, void *data, \
	void (*f)(int old_x, int old_y, int new_x, int new_y, void *data))
{
	int				new_x;
	int				new_y;

	SDL_GetWindowSize(esdl->en.win, &new_x, &new_y);
	if (new_x != esdl->en.rx || new_y != esdl->en.ry)
	{
		if (f != NULL)
		{
			f(esdl->en.rx, esdl->en.ry, new_x, new_y, data);
		}
		esdl->en.rx = new_x;
		esdl->en.ry = new_y;
	}
}

int					esdl_init(t_esdl *esdl, const int rx, const int ry, \
	char *engine_name)
{
	int				ret;

	esdl_init_esdl(esdl);
	ret = 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ret = -1;
		printf("%s\n", SDL_GetError());
	}
	esdl->en.win = SDL_CreateWindow(engine_name, SDL_WINDOWPOS_UNDEFINED, \
		SDL_WINDOWPOS_UNDEFINED, rx, ry, \
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (!esdl->en.win)
	{
		ret = -1;
		printf("%s\n", SDL_GetError());
	}
	esdl->en.rx = rx;
	esdl->en.ry = ry;
	esdl->en.ren = SDL_CreateRenderer(esdl->en.win, -1,
			SDL_RENDERER_ACCELERATED);
	if (!esdl->en.ren)
	{
		ret = -1;
		printf("%s\n", SDL_GetError());
	}
	return (ret);
}

void				esdl_quit(t_esdl *esdl)
{
	SDL_DestroyRenderer(esdl->en.ren);
	SDL_DestroyWindow(esdl->en.win);
	SDL_Quit();
}
