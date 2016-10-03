/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:40:03 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 15:40:04 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>

SDL_Color					esdl_int_to_color(int color)
{
	SDL_Color				ret_color;

	ret_color.r = (color >> 24) & 0xFF;
	ret_color.g = (color >> 16) & 0xFF;
	ret_color.b = (color >> 8) & 0xFF;
	ret_color.a = (color) & 0xFF;
	return (ret_color);
}

int							esdl_color_to_int(SDL_Color color)
{
	int						ret_color;

	ret_color = 0;
	ret_color = (ret_color << 8) + color.r;
	ret_color = (ret_color << 8) + color.g;
	ret_color = (ret_color << 8) + color.b;
	ret_color = (ret_color << 8) + color.a;
	return (ret_color);
}

static int		hsv_set_color(float r, float g, float b)
{
	return (\
		(int)(r * 255.0) << 24 |\
		(int)(g * 255.0) << 16 |\
		(int)(b * 255.0) << 8 |\
		255);
}

static void		hsv_to_rgb_else(float h, float s, float v, int *color)
{
	float 		f;
	float 		p;
	float 		q;
	float 		t;
	int			i;

	h *= 6;
	i = (int)floor(h);
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - (s * f));
	t = v * (1 - (s * (1 - f)));
	if (i == 0)
		*color = hsv_set_color(v, t, p);
	if (i == 1)
		*color = hsv_set_color(q, v, p);
	if (i == 2)
		*color = hsv_set_color(p, v, t);
	if (i == 3)
		*color = hsv_set_color(p, q, v);
	if (i == 4)
		*color = hsv_set_color(t, p, v);
	if (i == 5)
		*color = hsv_set_color(v, p, q);
}

int				esdl_hsv_to_rgb(float h, float s, float v)
{
	int			color;

	h = h / 256.0;
	s = s / 256.0;
	v = v / 256.0;
	if(s == 0)
		color = hsv_set_color(v, v, v);
	else
		hsv_to_rgb_else(h, s, v, &color);
	return (color);
}
