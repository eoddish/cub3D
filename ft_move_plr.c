/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:17:39 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/16 18:54:00 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_move_forward(t_all **all)
{
	t_all	*a;
	char	**map;

	a = *all;
	map = a->d->map;
	a->p->x += sin(a->p->dir);
	a->p->y += cos(a->p->dir);
	if (map[(int) a->p->x][(int)a->p->y] == '1')
	{
		a->p->x -= sin(a->p->dir);
		a->p->y -= cos(a->p->dir);
	}
}

void	ft_move_back(t_all **all)
{
	t_all	*a;
	char	**map;

	a = *all;
	map = a->d->map;
	a->p->x -= sin(a->p->dir);
	a->p->y -= cos(a->p->dir);
	if (map[(int) a->p->x][(int)a->p->y] == '1')
	{
		a->p->x += sin(a->p->dir);
		a->p->y += cos(a->p->dir);
	}
}

void	ft_move_left(t_all **all)
{
	t_all	*a;
	char	**map;

	a = *all;
	map = a->d->map;
	a->p->x -= cos(a->p->dir);
	a->p->y += sin(a->p->dir);
	if (map[(int) a->p->x][(int)a->p->y] == '1')
	{
		a->p->x += cos(a->p->dir);
		a->p->y -= sin(a->p->dir);
	}
}

void	ft_move_right(t_all **all)
{
	t_all	*a;
	char	**map;

	a = *all;
	map = a->d->map;
	a->p->x += cos(a->p->dir);
	a->p->y -= sin(a->p->dir);
	if (map[(int) a->p->x][(int)a->p->y] == '1')
	{
		a->p->x -= cos(a->p->dir);
		a->p->y += sin(a->p->dir);
	}
}

void	ft_move_plr(t_all **all)
{
	t_all	*a;
	t_mdata	*m;

	a = *all;
	m = a->m;
	if (m->key == 123)
		a->p->dir -= 0.1;
	else if (m->key == 124)
		a->p->dir += 0.1;
	else if (m->key == 13)
		ft_move_forward(all);
	else if (m->key == 0)
		ft_move_left(all);
	else if (m->key == 1)
		ft_move_back(all);
	else if (m->key == 2)
		ft_move_right(all);
}
