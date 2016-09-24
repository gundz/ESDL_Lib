/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:05:03 by fgundlac          #+#    #+#             */
/*   Updated: 2015/03/16 17:10:18 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_SDL_H
# define EASY_SDL_H

# include <SDL.h>
# include <SDL_image.h>

# define MAX_FPS 120

typedef struct			s_input
{
	char				key[SDL_NUM_SCANCODES];
	char				button[8];
	int					mw_y;
	int					m_x;
	int					m_y;
	int					m_r_x;
	int					m_r_y;
}						t_input;

typedef struct			s_engine
{
	SDL_Window			*win;
	int					rx;
	int					ry;
	SDL_Renderer		*ren;
	t_input				in;
}						t_engine;

typedef struct			s_pt
{
	float				x;
	float				y;
}						t_pt;

typedef struct			s_v2d
{
	long double			x;
	long double			y;
}						t_v2d;

typedef	struct			s_timer
{
	int					fps;
	int					current;
	int					update;
	int					limit;
	char				title[128];
	unsigned int		framelimit;
}						t_timer;

typedef	struct			s_esdl
{
	t_engine			en;
	t_timer				fps;
	int					run;
}						t_esdl;

# define SDL_RX data->esdl->en.rx
# define SDL_RY data->esdl->en.ry

int						esdl_init(t_esdl *esdl, \
	const int rx, const int ry, char *engine_name);
void					esdl_quit(t_esdl *esdl);

void					esdl_update_window_info(t_esdl *esdl, void *data, \
	void (*f)(int old_x, int old_y, int new_x, int new_y, void *data));

int						esdl_update_events(t_input *in, int *run);
int						esdl_check_input(t_input *in, const int input);

void					esdl_fps_counter(t_esdl *esdl);
void					esdl_fps_limit(t_esdl *esdl);

SDL_Surface				*esdl_create_surface(int width, int height);
void					esdl_put_pixel(SDL_Surface *const surf, \
	const int x, const int y, const int color);

SDL_Texture				*esdl_load_texture(t_esdl *esdl, char *path, \
	int *w, int *h);

SDL_Color				esdl_sdl_int_to_color(int color);
int						esdl_sdl_color_to_int(SDL_Color color);

int						esdl_hsv_to_rgb(float h, float s, float v);

void					esdl_draw_line(SDL_Surface *surf, SDL_Rect rect, \
	const int color);

void					esdl_draw_square(SDL_Surface *surf, \
	const SDL_Rect rect, const int color);
void					esdl_draw_filled_square(SDL_Surface *surf, \
	const SDL_Rect rect, const int color);

void					esdl_draw_circle(SDL_Surface *surf, SDL_Rect rect, \
	const int radius, const int color);

void					esdl_clear_screen(SDL_Surface *surf, const int color);

int						ft_abs(int num);

int						write_tga(char *name, unsigned int *img, \
	const int w, const int h);

unsigned int			get_color_from_surf(SDL_Surface *surf, \
	const int x, const int y);

void					putchar_fd(char c, int fd);

#endif
