/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_draw_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:16:12 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 16:16:13 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>

void			esdl_draw_square(SDL_Surface *surf, \
	SDL_Rect rect, const int color)
{
	int			i;
	int			j;

	i = 0;
	while (i < rect.h)
	{
		j = 0;
		while (j < rect.w)
		{
			if ((i == 0 || i == rect.h - 1) || (j == 0 || j == rect.w - 1))
				esdl_put_pixel(surf, j + rect.x, i + rect.y, color);
			j++;
		}
		i++;
	}
}

void			esdl_draw_filled_square(SDL_Surface *surf, \
	const SDL_Rect rect, const int color)
{
	int			x;
	int			y;

	y = 0;
	while (y < rect.h)
	{
		x = 0;
		while (x < rect.w)
		{
			esdl_put_pixel(surf, x + rect.x, y + rect.y, color);
			x++;
		}
		y++;
	}
}
