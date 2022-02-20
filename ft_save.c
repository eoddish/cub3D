/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 02:18:54 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/27 22:46:37 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_save_img(t_all **a, int fd)
{
	t_all	*all;
	char	*temp;
	int		line;
	int		i;

	all = *a;
	temp = all->put->adr;
	line = all->d->y - 1;
	while (line >= 0)
	{
		i = 0;
		while (i < all->put->len)
		{
			while (i < all->d->x * 4)
			{
				write (fd, temp + line
					* all->put->len + i, 1);
				i++;
			}
			write(1, "\0", 1);
			i++;
		}
		line--;
	}
	close(fd);
}

void	ft_save(t_all **a)
{
	int		fd;
	char	str[54];
	char	*div;
	int		n;

	fd = open("./save.bmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
		ft_error(a);
	ft_bzero(str, 54);
	str[0] = 0x42;
	str[1] = 0x4D;
	n = (*a)->d->x * (*a)->d->y * (*a)->put->bpp / 8 + 54;
	div = (char *)(&n);
	ft_memcpy(str + 2, div, 4);
	str[10] = 0x36;
	str[14] = 0x28;
	str[26] = 0x01;
	div = (char *)(&((*a)->d->x));
	ft_memcpy(str + 18, div, 4);
	div = (char *)(&((*a)->d->y));
	ft_memcpy(str + 22, div, 4);
	div = (char *)(&((*a)->put->bpp));
	ft_memcpy(str + 28, div, 2);
	write(fd, str, 54);
	ft_save_img(a, fd);
}
