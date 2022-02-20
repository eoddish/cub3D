/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:22:29 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/22 20:20:00 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

int	ft_compare(t_all *a, t_spr *temp, t_spr *comp)
{
	float	dist;
	float	dist1;
	float	dist2;

	dist1 = (float)temp->x - a->p->x;
	dist2 = (float)temp->y - a->p->y;
	dist = (dist1 * dist1 + dist2 * dist2);
	dist1 = (float)comp->x - a->p->x;
	dist2 = (float)comp->y - a->p->y;
	return ((dist1 * dist1 + dist2 * dist2) - dist);
}

t_spr	*ft_base_case(t_spr **sl, t_spr **t, t_spr **r)
{
	t_spr	*spr_last;
	t_spr	*temp;
	t_spr	*s;

	spr_last = *sl;
	temp = *t;
	s = *r;
	spr_last->next = temp;
	s = spr_last;
	temp = spr_last;
	return (s);
}

t_spr	*ft_insert(t_spr **spr, t_spr **sprlst, int n, t_all *a)
{
	t_spr	*s;
	t_spr	*spr_last;
	t_spr	*temp;
	int		ret;

	s = *spr;
	spr_last = *sprlst;
	spr_last->next = 0;
	temp = s;
	ret = -1;
	if (ft_compare(a, temp, spr_last) > 0)
		return (ft_base_case(&spr_last, &temp, &s));
	while (ret < 0 && n >= 0 && temp)
	{
		ret = ft_compare(a, temp->next, spr_last);
		if (ret >= 0)
		{
			spr_last->next = temp->next;
			temp->next = spr_last;
			break ;
		}
		temp = temp->next;
		n--;
	}
	return (s);
}

t_spr	*ft_sort_spr(t_all *a, t_spr *s)
{
	t_spr	*temp;
	t_spr	*pass;
	int		n;

	temp = s;
	n = 0;
	while (temp->next)
	{
		n++;
		if (ft_compare(a, temp, temp->next) > 0)
		{
			pass = temp->next;
			temp->next = temp->next->next;
			s = ft_insert(&s, &pass, n, a);
		}
		else
			temp = temp->next;
	}
	return (s);
}
