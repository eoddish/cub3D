/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:33:47 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 13:56:35 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_clear_spr(t_all **all)
{
	t_data	*d;
	t_spr	*temp;
	t_spr	*cur;

	d = (*all)->d;
	if (d->spr)
	{
		temp = d->spr;
		while (temp)
		{
			cur = temp;
			temp = temp->next;
			free(cur);
		}
	}
}

void	ft_clear_map(t_all **all)
{
	t_data	*d;
	int		i;
	t_all	*a;

	a = *all;
	if (a->g)
		free(a->g);
	d = (*all)->d;
	if (d->map)
	{
		i = 0;
		while ((d->map)[i])
		{
			free((d->map)[i]);
			i++;
		}
		free(d->map);
	}
	if (a->str1)
		free(a->str1);
	if (a->str2)
		free(a->str2);
}

void	ft_clear(t_all **all)
{
	t_data	*d;

	d = (*all)->d;
	if (d)
	{
		if (d->no)
			free(d->no);
		if (d->so)
			free(d->so);
		if (d->ea)
			free(d->ea);
		if (d->we)
			 free(d->we);
		if (d->s)
			 free(d->s);
		ft_clear_map(all);
		ft_clear_spr(all);
		if (d->rc)
			free(d->rc);
		if (d->rf)
			free(d->rf);
		free(d);
	}
}

void	ft_clear_text(t_all **all)
{
	t_all	*a;

	a = *all;
	if (a->no)
		free(a->no);
	if (a->so)
		free(a->so);
	if (a->ea)
		free(a->ea);
	if (a->we)
		free(a->we);
	if (a->s)
		free(a->s);
	if (a->put)
		free(a->put);
	if (a->p)
		free(a->p);
	if (a->sput)
		free(a->sput);
}

void	ft_clean(t_all **all)
{
	t_all	*a;

	a = *all;
	if (a)
	{
		if (a->put)
			if (a->put->img)
				mlx_destroy_image(a->m->mlx, a->put->img);
		ft_clear(all);
		ft_clear_text(all);
		if (a->m)
		{
			if (a->m->img)
				mlx_destroy_image(a->m->mlx, a->m->img);
			if (a->m->win)
				mlx_destroy_window(a->m->mlx, a->m->win);
			free(a->m);
		}
		free(a);
	}
}
