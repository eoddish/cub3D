/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:10:59 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/26 19:55:31 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_split_array_creator(char const *s, char c)
{
	int		i;
	int		n;
	char	**res;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	res = (char **)ft_calloc(n + 1, sizeof(char *));
	if (!res)
		return (0);
	res[n] = NULL;
	return (res);
}

static int	ft_split_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static char	**ft_split_clear(char ***r, int n)
{
	int		i;
	char	**res;

	res = *r;
	i = 0;
	while (i < n)
		free(res[i++]);
	free(res);
	return (0);
}

int	ft_line_creator(char ***r, const char *s, int n, int len)
{
	char	**res;

	res = *r;
	res[n] = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res[n])
	{
		ft_split_clear(&res, n);
		return (-1);
	}
	ft_strlcpy(res[n++], s - len, len + 1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len;
	int		n;

	if (!s)
		return (0);
	len = 0;
	n = 0;
	res = ft_split_array_creator(s, c);
	if (!res)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		len = ft_split_len(s, c);
		s = s + len;
		if (len != 0)
		{
			if (ft_line_creator(&res, s, n++, len) < 0)
				return (0);
		}
		len = 0;
	}
	return (res);
}
