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

/*		CONFIG		*/
# define RX             640
# define RY             480
# define MAX_FPS        60
# define NAME           "Engine"

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
    char                title[128];
    unsigned int		frameLimit;
}                       t_timer;

typedef struct          s_esdl
{
    t_engine            en;
    t_timer             fps;
    int                 run;
}                       t_esdl;

/*		CONFIG VAR, DO NOT TOUCH 		*/
# define MAX_FPS_VAL 1000 / MAX_FPS

int                     init_sdl(t_esdl *esdl);
void                    quit_sdl(t_esdl *esdl);

int                     update_events(t_input *in, int *run);

void                    fps_counter(t_esdl *esdl);
void                    fps_limit(t_esdl *esdl);

SDL_Surface             *sdl_create_surface(int width, int height);
void                    put_pixel(SDL_Surface *const surf,
        const int x, const int y, const int color);

SDL_Color               sdl_int_to_color(int color);
int                     sdl_color_to_int(SDL_Color color);

void                    draw_line(SDL_Surface *surf, SDL_Rect rect,
        const int color);
void                    draw_square(SDL_Surface *surf, const SDL_Rect rect,
        const int color);
void                    clear_screen(SDL_Surface *surf, const int color);

#endif
