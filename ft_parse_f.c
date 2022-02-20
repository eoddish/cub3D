/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:18:13 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 13:59:21 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		while (*line == ' ')
			line++;
		if (!ft_isdigit(*line))
			return (1);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (*line == ',' && i < 2)
			line++;
		i++;
	}
	if (*line)
		return (1);
	return (0);
}

void	ft_col_error(t_all **all, char ***n)
{
	char	**newline;
	int		i;

	newline = *n;
	i = 0;
	while (newline[i])
		free(newline[i++]);
	free(newline);
	ft_error(all);
}

void	ft_parse_f(t_all **all, char *line)
{
	char	**newline;
	int		i;

	line++;
	if ((*all)->d->rf || *line != ' ')
		ft_error(all);
	(*all)->d->rf = ft_calloc(1, sizeof(t_rf));
	if (!(*all)->d->rf)
		ft_error(all);
	newline = ft_split(line, ',');
	if (!newline)
		ft_error(all);
	i = 0;
	while (newline[i])
		i++;
	if (i < 3 || i > 3 || check_line(line))
		ft_col_error(all, &newline);
	(*all)->d->rf->r = ft_atoi(newline[0]);
	(*all)->d->rf->g = ft_atoi(newline[1]);
	(*all)->d->rf->b = ft_atoi(newline[2]);
	i = 0;
	while (newline[i])
		free(newline[i++]);
	free(newline);
}
