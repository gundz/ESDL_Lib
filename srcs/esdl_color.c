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

int
esdl_hsv_to_rgb(float h, float s, float v)
{
    float r, g, b; //this function works with floats between 0 and 1
    h = h / 256.0;
    s = s / 256.0;
    v = v / 256.0;
     //If saturation is 0, the color is a shade of gray
    if(s == 0) r = g = b = v;
        //If saturation > 0, more complex calculations are needed
    else
    {
        float f, p, q, t;
        int i;
        h *= 6; //to bring hue to a number between 0 and 6, better for the calculations
        i = (int)floor(h);  //e.g. 2.7 becomes 2 and 3.01 becomes 3 or 4.9999 becomes 4
        f = h - i;  //the fractional part of h
        p = v * (1 - s);
        q = v * (1 - (s * f));
        t = v * (1 - (s * (1 - f)));
        switch(i)
        {
            case 0: r = v; g = t; b = p; break;
            case 1: r = q; g = v; b = p; break;
            case 2: r = p; g = v; b = t; break;
            case 3: r = p; g = q; b = v; break;
            case 4: r = t; g = p; b = v; break;
            case 5: r = v; g = p; b = q; break;
        }
    }
    return (int)(r * 255.0) << 24 | (int)(g * 255.0) << 16 | (int)(b * 255.0) << 8 | 255;
}
