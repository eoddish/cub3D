/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:28:59 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 01:15:23 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_init_text(t_all **all)
{
	t_all	*a;

	a = *all;
	a->no = ft_calloc(1, sizeof(t_img));
	a->so = ft_calloc(1, sizeof(t_img));
	a->ea = ft_calloc(1, sizeof(t_img));
	a->we = ft_calloc(1, sizeof(t_img));
	a->s = ft_calloc(1, sizeof(t_img));
	a->put = ft_calloc(1, sizeof(t_img));
	a->sput = ft_calloc(1, sizeof(t_sput));
	if (!a->no || !a->so || !a->ea || !a->we
		|| !a->s || !a->put || !a->sput
		|| !a->p)
		ft_error(all);
}

void	ft_control(t_all **all)
{
	t_mdata	*m;

	m = (*all)->m;
	mlx_hook(m->win, 2, 1L << 0, key_hook, all);
	mlx_hook(m->win, 3, 1L << 1, key_released, all);
	mlx_hook(m->win, 17, 1L << 0, ft_quit, all);
	mlx_loop_hook(m->mlx, ft_maze, all);
	mlx_loop(m->mlx);
}

void	ft_adjust(t_all **all)
{
	t_data	*d;
	t_mdata	*m;
	int		sizex;
	int		sizey;

	d = (*all)->d;
	m = (*all)->m;
	mlx_get_screen_size(m->mlx, &sizex, &sizey);
	if (d->x > sizex)
		d->x = sizex;
	if (d->y > sizey)
		d->y = sizey;
}

void	ft_mlx(t_all **all)
{
	t_all	*a;
	t_mdata	*m;

	a = *all;
	m = ft_calloc(1, sizeof(t_mdata));
	if (!m)
		ft_error(all);
	a->m = m;
	m->mlx = mlx_init();
	ft_adjust(all);
	if (!a->d->save)
		m->win = mlx_new_window(m->mlx, a->d->x, a->d->y, "cub3D");
	m->img = mlx_new_image(m->mlx, a->d->x, a->d->y);
	m->adr = mlx_get_data_addr(m->img, &m->bpp, &m->len, &m->end);
	a->put->img = mlx_new_image(a->m->mlx, a->d->x, a->d->y);
	a->put->adr = mlx_get_data_addr(a->put->img, &a->put->bpp,
			&a->put->len, &a->put->end);
	m->key = -1;
	a->f = ft_rgb(a->d->rf->r, a->d->rf->g, a->d->rf->b);
	a->c = ft_rgb(a->d->rc->r, a->d->rc->g, a->d->rc->b);
	ft_image(all);
	if (a->d->save)
		ft_maze(all);
	ft_control(all);
}
