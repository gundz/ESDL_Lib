#include <easy_sdl.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

unsigned int		get_color_from_surf(SDL_Surface *surf,
	const int x, const int y)
{
	int			ret;
	Uint32		*pixels;

	pixels = (Uint32 *)surf->pixels;
	ret = pixels[(y * surf->w) + x];
	return (ret);
}

unsigned int					*surf_to_int(SDL_Surface *surf)
{
	int				i;
	int				j;
	unsigned int				*ret;

	if (!(ret = (unsigned int *)malloc(sizeof(unsigned int) *
		surf->w * surf->h)))
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

static void					ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void			write_tga_header(const int fd, const int w, const int h)
{
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(2, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd((w & 0x00ff), fd);
	ft_putchar_fd((w & 0xff00) / 256, fd);
	ft_putchar_fd((h & 0x00ff), fd);
	ft_putchar_fd((h & 0xff00) / 256, fd);
	ft_putchar_fd(24, fd);
	ft_putchar_fd(0x00, fd);
}

static void			write_data(const int fd, unsigned int *img, const unsigned int w, const unsigned int h)
{
	int				i;
	unsigned int	j;

	i = h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < w)
		{
			ft_putchar_fd((char)((img[(i * w) + j] >> 8) & 0xFF), fd);
			ft_putchar_fd((char)((img[(i * w) + j] >> 16) & 0xFF), fd);
			ft_putchar_fd((char)((img[(i * w) + j] >> 24) & 0xFF), fd);
			j++;
		}
		i--;
	}
}

int					write_tga(char *name, unsigned int *img, const int w, const int h)
{
	int				fd;

	if ((fd = save_file(name)) == -1)
		return (-1);
	write_tga_header(fd, w, h);
	write_data(fd, img, w, h);
	close(fd);
	return (0);
}