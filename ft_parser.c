/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:55:25 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/27 22:49:09 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_check_elem(t_all **all)
{
	t_all	*a;

	a = *all;
	if (!a->d->no || !a->d->so || !a->d->ea || !a->d->we
		|| !a->d->s || !a->d->map || !a->d->x
		|| !a->d->y || !a->d->rc || !a->d->rf)
		ft_error(all);
	if (a->d->rf->r < 0 || a->d->rf->r > 255
		|| a->d->rf->g < 0 || a->d->rf->g > 255
		|| a->d->rf->b < 0 || a->d->rf->b > 255
		|| a->d->rc->r < 0 || a->d->rc->r > 255
		|| a->d->rc->g < 0 || a->d->rc->g > 255
		|| a->d->rc->b < 0 || a->d->rc->b > 255
		|| a->d->x < 0 || a->d->y < 0)
		ft_error(all);
}

char	*ft_cat(t_all **all, char **oldline, char *line)
{
	char	*temp;
	char	*cur;
	char	*newline;

	newline = *oldline;
	temp = ft_calloc(2, 1);
	if (!temp)
	{
		free(newline);
		ft_error(all);
	}	
	temp[0] = '\n';
	temp[1] = '\0';
	cur = ft_strjoin(newline, temp);
	free(temp);
	free(newline);
	newline = ft_strjoin(cur, line);
	free(cur);
	return (newline);
}

void	ft_parse_map(t_all **all, char *line, int fd, t_gnl *g)
{
	int		ret;
	char	*newline;

	ret = 1;
	newline = ft_calloc(ft_strlen(line) + 1, 1);
	if (!newline)
		ft_error(all);
	ft_strlcpy(newline, line, ft_strlen(line) + 1);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line, g);
		if ((ret > 0 && ft_strlen(line) < 1) || ret < 0)
			ft_error(all);
		(*all)->str2 = line;
		newline = ft_cat(all, &newline, line);
		free(line);
		(*all)->str2 = 0;
	}
	(*all)->d->map = ft_split(newline, '\n');
	free(newline);
	if (!(*all)->d->map)
		ft_error(all);
	ft_parse_spr(&((*all)->d), (*all)->d->map);
	ft_mapcheck(all, (*all)->d->map);
}

void	ft_parse_elem(t_all **all, char *line, int fd, t_gnl *g)
{
	int	size;

	size = 0;
	while (line[size] == ' ')
		size++;
	if (line[size] == 'R')
		ft_parse_r(all, line + size);
	else if (line[size] == 'N' && line[size + 1] == 'O')
		ft_parse_no(all, line + size);
	else if (line[size] == 'S' && line[size + 1] == 'O')
		ft_parse_so(all, line + size);
	else if (line[size] == 'W' && line[size + 1] == 'E')
		ft_parse_we(all, line + size);
	else if (line[size] == 'E' && line[size + 1] == 'A')
		ft_parse_ea(all, line + size);
	else if (line[size] == 'S')
		ft_parse_s(all, line + size);
	else if (line[size] == 'F')
		ft_parse_f(all, line + size);
	else if (line[size] == 'C')
		ft_parse_c(all, line + size);
	else if (ft_isdigit(line[size]))
		ft_parse_map(all, line, fd, g);
	else if (line[size])
		ft_error(all);
}

void	ft_parser(char *map, t_all **all)
{
	int		fd;
	char	*line;
	int		ret;
	t_gnl	*g;

	line = 0;
	ret = 1;
	fd = open(map, O_RDONLY);
	g = ft_calloc(1, sizeof(t_gnl));
	(*all)->g = g;
	if (fd < 0 || !g)
		ft_error(all);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line, g);
		if (ret < 0)
			ft_error(all);
		(*all)->str1 = line;
		if (ret)
			ft_parse_elem(all, line, fd, g);
		free(line);
		(*all)->str1 = 0;
	}
	close(fd);
	ft_check_elem(all);
}
