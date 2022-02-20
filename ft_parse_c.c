/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:13:28 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 13:59:35 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_parse_c(t_all **all, char *line)
{
	char	**newline;
	int		i;

	line++;
	if ((*all)->d->rc || *line != ' ')
		ft_error(all);
	(*all)->d->rc = ft_calloc(1, sizeof(t_rc));
	if (!(*all)->d->rc)
		ft_error(all);
	newline = ft_split(line, ',');
	if (!newline)
		ft_error(all);
	i = 0;
	while (newline[i])
		i++;
	if (i < 3 || i > 3 || check_line(line))
		ft_col_error(all, &newline);
	(*all)->d->rc->r = ft_atoi(newline[0]);
	(*all)->d->rc->g = ft_atoi(newline[1]);
	(*all)->d->rc->b = ft_atoi(newline[2]);
	i = 0;
	while (newline[i])
		free(newline[i++]);
	free(newline);
}
