/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:13:25 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 01:18:57 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_put_spr(t_all **all, float *depthbuf)
{
	t_all	*a;
	t_spr	*temp;

	a = *all;
	if (a->d->spr)
		if (a->d->spr->next)
			a->d->spr = ft_sort_spr(a, a->d->spr);
	temp = a->d->spr;
	while (temp)
	{
		ft_draw_spr(all, (float)temp->x + 0.5, (float)temp->y
			+ 0.5, depthbuf);
		temp = temp->next;
	}
}

void	ft_fill_put(t_all **all)
{
	t_all	*a;
	int		x;
	int		y;
	t_img	*put;

	a = *all;
	x = 0;
	put = a->put;
	while (x < a->d->x)
	{
		y = 0;
		while (y < a->d->y)
		{
			a->put->adr[y * a->put->len + x * a->put->bpp / 8] = a->m->adr[y
				* a->m->len + x * (a->m->bpp / 8)];
			a->put->adr[y * a->put->len + x * a->put->bpp / 8 + 1] = a->m->adr[y
				* a->m->len + x * (a->m->bpp / 8) + 1];
			a->put->adr[y * a->put->len + x * a->put->bpp / 8 + 2] = a->m->adr[y
				* a->m->len + x * (a->m->bpp / 8) + 2];
			y++;
		}
		x++;
	}
}

int	ft_maze(t_all **all)
{
	float	*depthbuf;
	int		i;

	depthbuf = ft_calloc((*all)->d->x, sizeof(float));
	if (!depthbuf)
		ft_error(all);
	(*all)->sput->fov = M_PI_4;
	ft_move_plr(all);
	i = 0;
	while (i < (*all)->d->x)
	{
		depthbuf[i] = ft_ray_cast(all, (*all)->sput->fov, i);
		i++;
	}
	ft_put_spr(all, depthbuf);
	free(depthbuf);
	ft_fill_put(all);
	if ((*all)->d->save)
	{
		ft_save(all);
		ft_clean(all);
		exit(0);
	}
	return (mlx_put_image_to_window((*all)->m->mlx,
			(*all)->m->win, (*all)->put->img, 0, 0));
}
