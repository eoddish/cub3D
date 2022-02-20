/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:19:32 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/20 20:35:49 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_put_pixel(t_all **all, int x, int y, int col)
{	
	t_all			*a;
	t_mdata			*m;
	unsigned char	*src;

	a = *all;
	m = a->m;
	src = (unsigned char *)&col;
	m->adr[y * m->len + x * m->bpp / 8] = src[0];
	m->adr[y * m->len + x * m->bpp / 8 + 1] = src[1];
	m->adr[y * m->len + x * m->bpp / 8 + 2] = src[2];
}

void	ft_get_text_adr(t_all **all)
{
	t_all	*a;
	t_mdata	*m;

	a = *all;
	m = a->m;
	a->no->adr
		= mlx_get_data_addr(a->no->img, &a->no->bpp, &a->no->len, &a->no->end);
	a->so->adr
		= mlx_get_data_addr(a->so->img, &a->so->bpp, &a->so->len, &a->so->end);
	a->ea->adr
		= mlx_get_data_addr(a->ea->img, &a->ea->bpp, &a->ea->len, &a->ea->end);
	a->we->adr
		= mlx_get_data_addr(a->we->img, &a->we->bpp, &a->we->len, &a->we->end);
	a->s->adr
		= mlx_get_data_addr(a->s->img, &a->s->bpp, &a->s->len, &a->s->end);
}

void	ft_image(t_all **all)
{
	t_all	*a;
	t_mdata	*m;

	a = *all;
	m = a->m;
	a->no->img
		= mlx_xpm_file_to_image(m->mlx, a->d->no, &a->no->img_w, &a->no->img_h);
	a->so->img
		= mlx_xpm_file_to_image(m->mlx, a->d->so, &a->so->img_w, &a->so->img_h);
	a->ea->img
		= mlx_xpm_file_to_image(m->mlx, a->d->ea, &a->ea->img_w, &a->ea->img_h);
	a->we->img
		= mlx_xpm_file_to_image(m->mlx, a->d->we, &a->we->img_w, &a->we->img_h);
	a->s->img
		= mlx_xpm_file_to_image(m->mlx, a->d->s, &a->s->img_w, &a->s->img_h);
	if (!a->no->img || !a->so->img || !a->ea->img || !a->we->img || !a->s->img)
		ft_error(all);
	ft_get_text_adr(all);
}
