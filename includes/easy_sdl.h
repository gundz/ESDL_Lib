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

typedef struct          s_input
{
    char                key[SDL_NUM_SCANCODES];
    char                button[8];
    int                 mw_y;
    int                 m_x;
    int                 m_y;
    int                 m_r_x;
    int                 m_r_y;
}                       t_input;

typedef struct          s_engine
{
    SDL_Window          *win;
    int					rx;
    int					ry;
    SDL_Renderer        *ren;
    t_input             in;
}                       t_engine;

typedef struct          s_pt
{
    float               x;
    float               y;
}                       t_pt;

typedef struct          s_v2d
{
    long double         x;
    long double         y;
}                       t_v2d;

typedef struct          s_timer
{
    int                 fps;
    int                 current;
    int                 update;
    int					limit;
    char                title[128];
    unsigned int		frameLimit;
}                       t_timer;

typedef struct          s_esdl
{
    t_engine            en;
    t_timer             fps;
    int                 run;
}                       t_esdl;

int						Esdl_init(t_esdl *esdl, const int rx, const int ry, const int max_fps, char *engine_name);
void               	    Esdl_quit(t_esdl *esdl);

void					Esdl_update_window_info(t_esdl *esdl);

int                     Esdl_update_events(t_input *in, int *run);
int						Esdl_check_input(t_input *in, const int input);

void                    Esdl_fps_counter(t_esdl *esdl);
void                    Esdl_fps_limit(t_esdl *esdl);

SDL_Surface             *Esdl_create_surface(int width, int height);
void                    Esdl_put_pixel(SDL_Surface *const surf,
        const int x, const int y, const int color);

SDL_Texture				*Esdl_load_texture(t_esdl *esdl, char *path, int *w, int *h);

SDL_Color               Esdl_sdl_int_to_color(int color);
int                     Esdl_sdl_color_to_int(SDL_Color color);

void                    Esdl_draw_line(SDL_Surface *surf, SDL_Rect rect,
        const int color);

void                    Esdl_draw_square(SDL_Surface *surf, const SDL_Rect rect, const int color);
void                    Esdl_draw_filled_square(SDL_Surface *surf, const SDL_Rect rect, const int color);

void                    Esdl_draw_circle(SDL_Surface *surf, int x0, int y0, const int radius, const int color);

void                    Esdl_clear_screen(SDL_Surface *surf, const int color);

#endif
