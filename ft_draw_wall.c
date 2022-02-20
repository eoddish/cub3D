/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:45:04 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/17 18:31:59 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_wall_samp(t_all **all, int ceil, int floor, float samplex)
{
	t_all	*a;
	float	sampley;
	int		tempx;
	int		tempy;

	a = *all;
	sampley = ((float)a->m->y - (float)ceil)
		/ ((float)floor - (float)ceil);
	tempx = (int)(samplex * a->t->img_w);
	tempy = (int)(sampley * a->t->img_h);
	a->m->adr[a->m->y * a->m->len + a->m->x
		* a->m->bpp / 8] = a->t->adr[tempy
		* a->t->len + tempx * (a->t->bpp / 8)];
	a->m->adr[a->m->y * a->m->len + a->m->x
		* a->m->bpp / 8 + 1] = a->t->adr[tempy
		* a->t->len + tempx * (a->t->bpp / 8) + 1];
	a->m->adr[a->m->y * a->m->len + a->m->x
		* a->m->bpp / 8 + 2] = a->t->adr[tempy
		* a->t->len + tempx * (a->t->bpp / 8) + 2];
}

void	ft_draw_wall(t_all **all, int ceil, float samplex, int x)
{
	t_all	*a;
	t_mdata	*m;
	t_img	*t;
	int		floor;
	int		y;

	a = *all;
	m = a->m;
	t = a->t;
	floor = a->d->y - ceil;
	y = 0;
	while (y < a->d->y)
	{
		if (y < ceil)
			ft_put_pixel(all, x, y, (*all)->c);
		else if (y >=ceil && y < floor)
		{
			a->m->x = x;
			a->m->y = y;
			ft_wall_samp(all, ceil, floor, samplex);
		}
		else
			ft_put_pixel(all, x, y, (*all)->f);
		y++;
	}
}
