/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:40:12 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 15:40:13 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>

#include <stdio.h>

void				esdl_fps_counter(t_esdl *esdl)
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

static void			esdl_fps_limit_delay(t_esdl *esdl, \
	const unsigned int framelimit)
{
	unsigned int	ticks;
	int				max;

	ticks = SDL_GetTicks();
	max = (1000 / esdl->fps.limit);
	if (framelimit < ticks)
		return ;
	if (framelimit > ticks + max)
		SDL_Delay(max);
	else
		SDL_Delay(framelimit - ticks);
}

void				esdl_fps_limit(t_esdl *esdl)
{
	esdl_fps_limit_delay(esdl, esdl->fps.framelimit);
	esdl->fps.framelimit = SDL_GetTicks() + (1000 / esdl->fps.limit);
}
