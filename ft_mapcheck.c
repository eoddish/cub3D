/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:01:03 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/27 20:01:44 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

int	ft_bdrcheck(char **map, int i, int j)
{
	if (i == 0 || map[i + 1] == 0)
		return (1);
	else if (j == 0 || map[i][j + 1] == 0)
		return (1);
	return (0);
}

int	ft_possible(char c)
{
	char	*possible;

	possible = "02NSWE";
	while (*possible)
	{
		if (*possible == c)
			return (1);
		possible++;
	}
	return (0);
}

int	ft_sqcheck(char **map, int i, int j)
{
	int	x;
	int	y;

	x = -1;
	while (x < 2)
	{
		y = -1;
		while (y < 2)
		{
			if (j + y > (int)(ft_strlen(map[i + x])))
				return (1);
			if (map[i + x][j + y] == ' ' || map[i + x][j + y] == '\0')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_mapcheck(t_all **all, char **map)
{
	int		err;	
	int		i;
	int		j;

	err = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_possible(map[i][j]) && map[i][j] != ' '
			&& map[i][j] != '1')
				ft_error(all);
			if (ft_possible(map[i][j]))
			{
				if (ft_bdrcheck(map, i, j))
					ft_error(all);
				if (ft_sqcheck(map, i, j))
					ft_error(all);
			}
			j++;
		}	
		i++;
	}
}
