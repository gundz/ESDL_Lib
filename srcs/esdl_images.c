#include <easy_sdl.h>

#include <stdio.h>

SDL_Texture			*Esdl_load_texture(t_esdl *esdl, char *path, int *w, int *h)
{
	SDL_Surface		*surf;
	SDL_Texture		*tex;
	SDL_Rect		rect;

	surf = IMG_Load(path);
	if (w != NULL)
		*w = surf->w;
	if (h != NULL)
		*h = surf->h;
	if (!surf)
	{
		printf("Error while loading texture : \"%s\", fallback texture created\n", path);
		rect.x = 0;
		rect.y = 0;
		rect.w = 32;
		rect.h = 32;
		if (w != NULL)
			*w = 32;
		if (h != NULL)
			*h = 32;
		surf = Esdl_create_surface(32, 32);
		Esdl_draw_square(surf, rect, 0xFF69B4FF);
	}
	tex = SDL_CreateTextureFromSurface(esdl->en.ren, surf);
	SDL_FreeSurface(surf);
	return (tex);
}