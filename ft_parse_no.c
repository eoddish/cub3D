/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_no.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:00:37 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/27 22:52:28 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_parse_no(t_all **all, char *line)
{
	t_data	*d;

	d = (*all)->d;
	if (d->no)
		ft_error(all);
	line += 2;
	if (*line != ' ')
		ft_error(all);
	line = ft_strtrim(line, " ");
	if (ft_strncmp(line + ft_strlen(line) - 4, ".xpm", 5))
		ft_error(all);
	d->no = line;
}
