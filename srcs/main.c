#include <easy_sdl.h>
#include <SDL.h>

void					test(t_esdl *esdl)
{
	static SDL_Rect		rect = {0, 0, 200, 200};
	static SDL_Texture 	*square = NULL;
	SDL_Surface			*surf;

	if (square == NULL)
	{
		surf = sdl_create_surface(200, 200);
		draw_square(surf, rect, 0xFFFFFFFF);
		square = SDL_CreateTextureFromSurface(esdl->en.ren, surf);
	}
	if (rect.x >= RX)
		rect.x = 0;
	if (rect.y >= RY)
		rect.y = 0;
	rect.x++;
	rect.y++;
	SDL_RenderClear(esdl->en.ren);
	SDL_RenderCopy(esdl->en.ren, square, NULL, &rect);
	SDL_RenderPresent(esdl->en.ren);
}

int					main(int argc, char **argv)
{
	t_esdl			esdl;

	if (init_sdl(&esdl) == -1)
		return (-1);
	while (!check_input(&esdl, SDL_SCANCODE_ESCAPE))
	{
		update_events(&esdl.en.in, &esdl.run);

		test(&esdl);

		fps_limit(&esdl);
		fps_counter(&esdl);
	}
	quit_sdl(&esdl);
	(void)argc;
	(void)argv;
	return (0);
}
