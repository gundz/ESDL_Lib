/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:40:14 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 15:40:16 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>

#include <stdio.h>

static SDL_Surface	*create_fallback_texture(SDL_Surface *surf)
{
	SDL_Rect		rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = 32;
	rect.h = 32;
	surf = esdl_create_surface(32, 32);
	esdl_draw_filled_square(surf, rect, 0xFF69B4FF);
	return (surf);
}

SDL_Texture			*esdl_load_texture(t_esdl *esdl, char *path, \
	int *w, int *h)
{
	SDL_Surface		*surf;
	SDL_Texture		*tex;

	surf = IMG_Load(path);
	if (w != NULL)
		*w = surf->w;
	if (h != NULL)
		*h = surf->h;
	if (!surf)
	{
		printf("Error while loading texture : \"%s\", \
			fallback texture created\n", path);
		surf = create_fallback_texture(surf);
	}
	tex = SDL_CreateTextureFromSurface(esdl->en.ren, surf);
	SDL_FreeSurface(surf);
	return (tex);
}
