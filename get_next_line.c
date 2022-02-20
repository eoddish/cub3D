/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:31:39 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/22 22:39:19 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	ft_fill(char **line, char *previous, int off, t_list *move)
{
	int	x;
	int	j;
	int	k;

	x = 0;
	while (has_newline(previous, off) != x + off && x + off < 1)
	{
		*(*line + x) = previous[x + off];
		x++;
	}
	k = 0;
	while (move)
	{
		j = 0;
		while (j < 1)
		{
			if (has_newline((char *)(move->content), 0) == j)
				break ;
			*(*line + j + k * 1 + x) = ((char *)(move->content))[j];
			j++;
		}
		move = move->next;
		k++;
	}
}

char	*ft_prep(char *previous, int *off, t_list **lst, int fl)
{
	int		x;
	t_list	*move;

	move = *lst;
	if (move)
		while (move->next)
			move = move->next;
	x = 0;
	while (has_newline(previous, *off) != x + *off && x + *off < 1)
		x++;
	if (*lst)
	{
		ftg_bzero(previous, 1);
		ftg_strncpy(previous, move->content, 1);
		*off = has_newline(move->content, 0) + 1;
		ftg_lstclear(lst, free);
	}
	else
		*off = *off + x + 1;
	if (*off == 1 || (fl < 1 && (*off > fl || *off == 0)))
	{
		*off = 0;
		ftg_bzero(previous, 1);
	}
	return (previous);
}

int	ft_reading_in(t_list **lst, char **buf, int fd)
{
	int	flag;
	int	re;

	flag = 0;
	re = 1;
	ftg_bzero(*buf, 1);
	while (re > 0)
	{
		flag = read(fd, *buf, 1);
		re = flag;
		if (ftg_create_list(lst, *buf) == -1)
		{
			ftg_lstclear(lst, free);
			free(*buf);
			return (-1);
		}
		if (has_newline(*buf, 0) >= 0)
			break ;
		ftg_bzero(*buf, 1);
	}
	if (flag == -1)
		if (*buf)
			free(*buf);
	return (flag);
}

char	*ft_create_line(char **buf, char *previous, t_list *lst, int offset)
{
	int		size;
	char	*line;
	int		n;

	n = 0;
	size = 0;
	while (lst)
	{
		n++;
		lst = lst->next;
	}
	if (n)
		size += 1 * (n - 1);
	if (offset && has_newline(previous, offset) > -1)
		size += has_newline(previous, offset) - offset;
	else if (offset)
		size += 1 - offset;
	size += has_newline(*buf, 0);
	line = (char *)malloc(size + 1);
	if (!line && lst)
		ftg_lstclear(&lst, free);
	ftg_bzero(line, size + 1);
	if (*buf)
		free(*buf);
	return (line);
}

int	get_next_line(int fd, char **line, t_gnl *g)
{
	g->buf = malloc(1);
	if (!line || fd < 0 || !g->buf)
		return (-1);
	g->lst = 0;
	ftg_bzero(g->buf, 1);
	if (has_newline(g->prev, g->off) == -1 || g->off == 0)
	{
		g->flag = ft_reading_in(&g->lst, &g->buf, fd);
		if (g->flag < 0)
			return (-1);
	}
	*line = ft_create_line(&g->buf, g->prev, g->lst, g->off);
	if (!(*line))
		return (-1);
	ft_fill(line, g->prev, g->off, g->lst);
	ftg_strncpy(g->prev, (g->buf = ft_prep(g->prev,
				&g->off, &g->lst, g->flag)), 1);
	if (g->flag < 1 && (g->off > g->flag || g->off == 0))
		return (0);
	if (g->flag == g->off)
	{
		g->off = 0;
		ftg_bzero(g->prev, 1);
	}
	return (1);
}
