/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:36:56 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/25 23:39:55 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

float	ft_def_wall(t_all **all, int testx, int testy, float distwall)
{
	float	testpntx;
	float	testpnty;
	float	testang;

	testpntx = (*all)->p->x + (*all)->eyex * distwall;
	testpnty = (*all)->p->y + (*all)->eyey * distwall;
	testang = atan2((testpnty - (float)testy
				- 0.5), (testpntx - (float)testx - 0.5));
	if (testang >= -M_PI * 0.25 && testang < M_PI * 0.25)
	{
		(*all)->t = (*all)->so;
		return (testpnty - (float)testy);
	}
	else if (testang >= M_PI * 0.25 && testang < M_PI * 0.75)
	{
		(*all)->t = (*all)->ea;
		return (testpntx - (float)testx);
	}
	else if (testang < -M_PI * 0.25 && testang >= -M_PI * 0.75)
	{
		(*all)->t = (*all)->we;
		return (testpntx - (float)testx);
	}
	(*all)->t = (*all)->no;
	return (testpnty - (float)testy);
}

void	ft_prep_dda(t_all **all, float unistepx, float unistepy)
{
	(*all)->testx = (int)((*all)->p->x);
	(*all)->testy = (int)((*all)->p->y);
	if ((*all)->eyex < 0)
	{
		(*all)->stepx = -1;
		(*all)->raylenx = (((*all)->p->x) - (float)((*all)->testx)) * unistepx;
	}
	else
	{
		(*all)->stepx = 1;
		(*all)->raylenx = ((float)((*all)->testx + 1.0)
				- ((*all)->p->x)) * unistepx;
	}
	if ((*all)->eyey < 0)
	{
		(*all)->stepy = -1;
		(*all)->rayleny = (((*all)->p->y) - (float)((*all)->testy)) * unistepy;
	}
	else
	{
		(*all)->stepy = 1;
		(*all)->rayleny = ((float)((*all)->testy + 1.0)
				- ((*all)->p->y)) * unistepy;
	}
}

float	ft_implem_dda(t_all **all, float unistepx, float unistepy)
{
	int		tile;
	float	distance;

	tile = 0;
	distance = 0.0;
	while (!tile)
	{
		if ((*all)->raylenx < (*all)->rayleny)
		{
			(*all)->testx += (*all)->stepx;
			distance = (*all)->raylenx;
			(*all)->raylenx += unistepx;
		}
		else
		{
			(*all)->testy += (*all)->stepy;
			distance = (*all)->rayleny;
			(*all)->rayleny += unistepy;
		}
		if ((*all)->d->map[(*all)->testx][(*all)->testy] == '1')
			tile = 1;
	}
	return (distance);
}

float	ft_ray_cast(t_all **all, float fov, int i)
{
	float	rayangle;
	float	samplex;
	float	unistepx;
	float	unistepy;
	float	distance;

	rayangle = ((*all)->p->dir - fov / 2.0) + ((float)i
			/ (float)((*all)->d->x)) * fov;
	(*all)->eyex = sin(rayangle);
	(*all)->eyey = cos(rayangle);
	unistepx = sqrt(1 + ((*all)->eyey / (*all)->eyex)
			* ((*all)->eyey / (*all)->eyex));
	unistepy = sqrt(1 + ((*all)->eyex / (*all)->eyey)
			* ((*all)->eyex / (*all)->eyey));
	ft_prep_dda(all, unistepx, unistepy);
	distance = ft_implem_dda(all, unistepx, unistepy);
	samplex = ft_def_wall(all, (*all)->testx, (*all)->testy, distance);
	ft_draw_wall(all, (float)((*all)->d->y / 2.0) - (*all)->d->y
		/ (((float)distance) * cos(rayangle - (*all)->p->dir)), samplex, i);
	return (distance);
}
