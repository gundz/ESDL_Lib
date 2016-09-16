/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:10:56 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 16:13:25 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>

void			esdl_put_pixel(SDL_Surface *const surf, \
	const int x, const int y, const int color)
{
	Uint32		*pixels;

	if ((x >= 0 && y >= 0) && (x < surf->w && y < surf->h))
	{
		pixels = (Uint32 *)surf->pixels;
		pixels[(y * surf->w) + x] = color;
	}
}

void			esdl_draw_circle(SDL_Surface *surf, SDL_Rect rect, \
	const int radius, const int color)
{
	int			x;
	int			y;
	int			m;

	x = 0;
	y = radius;
	m = 5 - 4 * radius;
	while (x <= y)
	{
		esdl_put_pixel(surf, x + rect.x, y + rect.y, color);
		esdl_put_pixel(surf, y + rect.x, x + rect.y, color);
		esdl_put_pixel(surf, -x + rect.x, y + rect.y, color);
		esdl_put_pixel(surf, -y + rect.x, x + rect.y, color);
		esdl_put_pixel(surf, x + rect.x, -y + rect.y, color);
		esdl_put_pixel(surf, y + rect.x, -x + rect.y, color);
		esdl_put_pixel(surf, -x + rect.x, -y + rect.y, color);
		esdl_put_pixel(surf, -y + rect.x, -x + rect.y, color);
		if (m > 0)
		{
			y -= 1;
			m = m - 8 * y;
		}
		x += 1;
		m += 8 * x + 4;
	}
}

void			esdl_draw_line(SDL_Surface *surf, SDL_Rect rect, \
	const int color)
{
	t_pt		d;
	t_pt		s;
	int			err;
	int			e2;

	d.x = ft_abs(rect.w - rect.x);
	d.y = ft_abs(rect.h - rect.y);
	s.x = (rect.x < rect.w ? 1 : -1);
	s.y = (rect.y < rect.h ? 1 : -1);
	err = d.x - d.y;
	while (rect.x != rect.w || rect.y != rect.h)
	{
		esdl_put_pixel(surf, rect.x, rect.y, color);
		if ((e2 = 2 * err) > -d.y)
			err -= (d.y + 0 * (rect.x += s.x));
		if (rect.x == rect.w && rect.y == rect.h)
		{
			esdl_put_pixel(surf, rect.x, rect.y, color);
			return ;
		}
		if (e2 < d.x)
			err += (d.x + 0 * (rect.y += s.y));
	}
}

void			esdl_clear_screen(SDL_Surface *surf, const int color)
{
	int			x;
	int			y;

	y = 0;
	while (y < surf->h)
	{
		x = 0;
		while (x < surf->w)
		{
			esdl_put_pixel(surf, x, y, color);
			x++;
		}
		y++;
	}
}
