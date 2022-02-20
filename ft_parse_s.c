/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:14:18 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/27 22:52:11 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_parse_s(t_all **all, char *line)
{
	t_data	*d;

	d = (*all)->d;
	if (d->s)
		ft_error(all);
	line++;
	if (*line != ' ')
		ft_error(all);
	line = ft_strtrim(line, " ");
	if (ft_strncmp(line + ft_strlen(line) - 4, ".xpm", 5))
		ft_error(all);
	d->s = line;
}
