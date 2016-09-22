/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:14:23 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/16 16:14:25 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>
#include <unistd.h>

int						ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

inline unsigned int		get_color_from_surf(SDL_Surface *surf, \
	const int x, const int y)
{
	int				ret;
	Uint32			*pixels;

	pixels = (Uint32 *)surf->pixels;
	ret = pixels[(y * surf->w) + x];
	return (ret);
}

inline void				putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
