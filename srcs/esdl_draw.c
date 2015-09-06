#include <easy_sdl.h>
#include <SDL.h>

int				ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void			Esdl_put_pixel(SDL_Surface *const surf, const int x, const int y, const int color)
{
	int			bpp;
	Uint32		*p;

	if ((x >= 0 && y >= 0) && (x < surf->w && y < surf->h))
	{
		SDL_LockSurface(surf);
		bpp = surf->format->BytesPerPixel;
		p = surf->pixels + y * surf->pitch + x * bpp;
		*(Uint32 *)p = color;
		SDL_UnlockSurface(surf);
	}
}

void			Esdl_draw_circle(SDL_Surface *surf, int x0, int y0, const int radius, const int color)
{
	int			x = 0;
	int			y = radius;
	int			m = 5 - 4 * radius;

	while (x <= y)
	{
		Esdl_put_pixel(surf, x + x0, y + y0, color);
		Esdl_put_pixel(surf, y + x0, x + y0, color);

		Esdl_put_pixel(surf, -x + x0, y + y0, color);
		Esdl_put_pixel(surf, -y + x0, x + y0, color);

		Esdl_put_pixel(surf, x + x0, -y + y0, color);
		Esdl_put_pixel(surf, y + x0, -x + y0, color);

		Esdl_put_pixel(surf, -x + x0, -y + y0, color);
		Esdl_put_pixel(surf, -y + x0, -x + y0, color);
		if (m > 0)
		{
			y -= 1;
			m = m - 8 * y;
		}
		x += 1;
		m += 8 * x + 4;
	}
}

void			Esdl_draw_square(SDL_Surface *surf, SDL_Rect rect, const int color)
{
	int			i;
	int			j;

	i = rect.y;
	while (i < rect.h)
	{
		j = rect.x;
		while (j < rect.w)
		{
			if ((i == 0 || i == rect.h - 1) || (j == 0 || j == rect.w - 1))
				Esdl_put_pixel(surf, j, i, color);
			j++;
		}
		i++;
	}
}

void			Esdl_draw_line(SDL_Surface *surf, SDL_Rect rect, const int color)
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
		Esdl_put_pixel(surf, rect.x, rect.y, color);
		if ((e2 = 2 * err) > -d.y)
			err -= (d.y + 0 * (rect.x += s.x));
		if (rect.x == rect.w && rect.y == rect.h)
		{
			Esdl_put_pixel(surf, rect.x, rect.y, color);
			return ;
		}
		if (e2 < d.x)
			err += (d.x + 0 * (rect.y += s.y));
	}
}

void		Esdl_draw_filled_square(SDL_Surface *surf, const SDL_Rect rect, const int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < rect.h)
	{
		x = 0;
		while (x < rect.w)
		{
			Esdl_put_pixel(surf, x + rect.x, y + rect.y, color);
			x++;
		}
		y++;
	}
}

void		Esdl_clear_screen(SDL_Surface *surf, const int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < surf->h)
	{
		x = 0;
		while (x < surf->w)
		{
			Esdl_put_pixel(surf, x, y, color);
			x++;
		}
		y++;
	}
}
