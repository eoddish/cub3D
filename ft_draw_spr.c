/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:29:02 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/19 21:29:13 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_spr_put(t_all **all, int tempx, int tempy)
{
	t_all	*a;
	int		x;
	int		y;

	a = *all;
	x = a->testx;
	y = a->testy;
	if ((unsigned int)(a->s->adr[tempy * a->s->len + tempx
			* (a->s->bpp / 8) + 3]) == 0x00 )
	{
		a->m->adr[y * a->m->len + x * a->m->bpp / 8] = a->s->adr[tempy
			* a->s->len + tempx * (a->s->bpp / 8)];
		a->m->adr[y * a->m->len + x * a->m->bpp / 8 + 1] = a->s->adr[tempy
			* a->s->len + tempx * (a->s->bpp / 8) + 1];
		a->m->adr[y * a->m->len + x * a->m->bpp / 8 + 2] = a->s->adr[tempy
			* a->s->len + tempx * (a->s->bpp / 8) + 2];
	}
}

void	ft_spr_samp_cont(t_all **all, float sprdist,
		float midspr, float *depthbuf)
{
	t_all	*a;

	a = *all;
	a->sput->ly = 0;
	while (a->sput->ly < a->sput->sprheight)
	{
		a->testx = (int)(midspr + a->sput->lx - (a->sput->sprwidth / 2.0));
		if (a->testx >= 0 && a->testx < a->d->x)
		{
			a->testy = (int)(a->sput->sprceil + a->sput->ly);
			if (depthbuf[a->testx] >= sprdist)
				ft_spr_put(all, (int)(a->sput->lx / a->sput->sprwidth
						* a->s->img_w), (int)(a->sput->ly
						/ a->sput->sprheight * a->s->img_h));
		}
		a->sput->ly += 1;
	}
}

int	ft_spr_samp(t_all **all, float sprdist, float midspr, float *depthbuf)
{
	t_all	*a;

	a = *all;
	a->sput->sprceil = (float)(a->d->y / 2.0) - a->d->y / ((float) sprdist);
	if (a->sput->sprceil < 0)
		return (0);
	a->sput->sprheight = a->d->y - 2.0 * a->sput->sprceil;
	a->sput->sprwidth = a->sput->sprheight
		/ ((float) a->s->img_h / (float) a->s->img_w);
	a->sput->lx = 0;
	while (a->sput->lx < a->sput->sprwidth)
	{
		ft_spr_samp_cont(all, sprdist, midspr, depthbuf);
		a->sput->lx += 1;
	}
	return (1);
}

int	ft_draw_spr(t_all **all, float spritex,
		float spritey, float *depthbuf)
{
	t_all	*a;
	float	sprdist;
	float	sprangle;

	a = *all;
	sprdist = sqrt((spritex - a->p->x) * (spritex - a->p->x)
			+ (spritey - a->p->y) * (spritey - a->p->y));
	sprangle = atan2(cos(a->p->dir), sin(a->p->dir))
		- atan2(spritey - a->p->y, spritex - a->p->x);
	if (a->d->map[(int) spritex][(int) spritey] == '1')
		return (0);
	if (sprangle < -M_PI)
		sprangle += 2.0 * M_PI;
	if (sprangle > M_PI)
		sprangle -= 2.0 * M_PI;
	if ((fabs(sprangle) < a->sput->fov / 2.0) && sprdist >= 0.5)
	{
		if (!ft_spr_samp(all, sprdist, (0.5 * (sprangle / (a->sput->fov
							/ 2.0)) + 0.5) * (float) a->d->x, depthbuf))
			return (0);
	}
	return (0);
}
