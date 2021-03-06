/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_surface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:40:20 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 15:40:22 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

SDL_Surface			*esdl_create_surface(int width, int height)
{
	SDL_Surface		*surf;

	surf = SDL_CreateRGBSurface(0, width, height, 32,
		0xFF000000,
		0x00FF0000,
		0x0000FF00,
		0x000000FF);
	return (surf);
}
