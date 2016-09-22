/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:31:13 by fgundlac          #+#    #+#             */
/*   Updated: 2016/09/22 18:31:14 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easy_sdl.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

unsigned int		*surf_to_int(SDL_Surface *surf)
{
	int				i;
	int				j;
	unsigned int	*ret;

	if (!(ret = (unsigned int *)malloc(\
		sizeof(unsigned int) * surf->w * surf->h)))
		return (NULL);
	i = 0;
	while (i < surf->h)
	{
		j = 0;
		while (j < surf->w)
		{
			ret[(surf->w * i) + j] = get_color_from_surf(surf, j, i);
			j++;
		}
		i++;
	}
	return (ret);
}

static int			save_file(const char *const name)
{
	int				fd;

	if ((fd = open(name,
		O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH)) == -1)
		return (-1);
	return (fd);
}

static void			write_tga_header(const int fd, const int w, const int h)
{
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(2, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd(0, fd);
	putchar_fd((w & 0x00ff), fd);
	putchar_fd((w & 0xff00) / 256, fd);
	putchar_fd((h & 0x00ff), fd);
	putchar_fd((h & 0xff00) / 256, fd);
	putchar_fd(24, fd);
	putchar_fd(0x00, fd);
}

static void			write_data(const int fd, unsigned int *img, \
	const unsigned int w, const unsigned int h)
{
	int				i;
	unsigned int	j;

	i = h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < w)
		{
			putchar_fd((char)((img[(i * w) + j] >> 8) & 0xFF), fd);
			putchar_fd((char)((img[(i * w) + j] >> 16) & 0xFF), fd);
			putchar_fd((char)((img[(i * w) + j] >> 24) & 0xFF), fd);
			j++;
		}
		i--;
	}
}

int					write_tga(char *name, unsigned int *img, \
	const int w, const int h)
{
	int				fd;

	if ((fd = save_file(name)) == -1)
		return (-1);
	write_tga_header(fd, w, h);
	write_data(fd, img, w, h);
	close(fd);
	return (0);
}
