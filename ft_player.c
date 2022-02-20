/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:36:12 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/25 23:04:10 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

int	ft_search(char **map, int i, int j)
{
	if (map[i][j] == 'N')
		return (1);
	else if (map[i][j] == 'S')
		return (2);
	else if (map[i][j] == 'E')
		return (3);
	else if (map[i][j] == 'W')
		return (4);
	return (0);
}

void	ft_fill_plr(int i, int j, t_all **all, int ret)
{
	t_all	*a;
	t_plr	*plr;

	a = *all;
	a->p = ft_calloc(1, sizeof(t_plr));
	if (!a->p)
		ft_error(all);
	plr = a->p;
	plr->x = i + 0.5;
	plr->y = j + 0.5;
	if (ret == 1)
		plr->dir = -M_PI_2;
	else if (ret == 2)
		plr->dir = M_PI_2;
	else if (ret == 3)
		plr->dir = 0;
	else
		plr->dir = M_PI;
}

void	ft_player(t_all **all)
{
	int	ret;
	int	i;
	int	j;
	int	already_one;

	ret = 0;
	already_one = 0;
	i = 0;
	while (((*all)->d->map)[i])
	{
		j = 0;
		while (((*all)->d->map)[i][j])
		{
			ret = ft_search((*all)->d->map, i, j);
			if (ret)
			{
				if (already_one)
					ft_error(all);
				already_one++;
				ft_fill_plr(i, j, all, ret);
			}
			j++;
		}
		i++;
	}
}
