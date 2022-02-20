/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:15:32 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 13:09:37 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_parse_r(t_all **all, char *line)
{
	t_data	*d;

	d = (*all)->d;
	if (d->x || d->y)
		ft_error(all);
	line++;
	if (*line != ' ')
		ft_error(all);
	while (*line == ' ')
		line++;
	d->x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	d->y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (*line)
		ft_error(all);
}
