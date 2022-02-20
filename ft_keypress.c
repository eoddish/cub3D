/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:50:46 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/27 21:24:37 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

int	key_released(int keycode, t_all **all)
{
	t_all	*a;
	t_mdata	*m;

	a = *all;
	m = a->m;
	m->key = -1;
	return (keycode);
}

int	ft_quit(t_all **all)
{
	t_all	*a;
	t_mdata	*m;

	a = *all;
	m = a->m;
	ft_clean(all);
	exit(0);
}

int	key_hook(int keycode, t_all **all)
{
	t_all	*a;
	t_mdata	*m;

	a = *all;
	m = a->m;
	if (keycode == 53)
	{
		ft_clean(all);
		exit(0);
	}
	m->key = keycode;
	return (0);
}
