/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_so.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:19:49 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/27 22:51:47 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_parse_so(t_all **all, char *line)
{
	t_data	*d;

	d = (*all)->d;
	if (d->so)
		ft_error(all);
	line += 2;
	if (*line != ' ')
		ft_error(all);
	line = ft_strtrim(line, " ");
	if (ft_strncmp(line + ft_strlen(line) - 4, ".xpm", 5))
		ft_error(all);
	d->so = line;
}
