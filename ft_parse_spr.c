/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 09:28:46 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/22 09:33:59 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_parse_spr(t_data **data, char **map)
{
	t_spr	*newlist;
	t_spr	*newone;
	int		i;
	int		j;

	newlist = NULL;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				newone = ft_calloc(1, sizeof(t_spr));
				newone->x = i;
				newone->y = j;
				newone->next = newlist;
				newlist = newone;
			}
			j++;
		}
		i++;
	}
	(*data)->spr = newlist;
}
