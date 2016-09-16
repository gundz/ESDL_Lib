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
