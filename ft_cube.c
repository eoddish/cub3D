/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:31:34 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 13:56:27 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cube.h"

void	ft_error(t_all **all)
{
	perror("Error\n");
	ft_clean(all);
	exit(0);
}

void	ft_arg_error(void)
{
	write(2, "Error\n", 6);
	write(2, ": Wrong arguments\n", 18);
	exit(0);
}

static void	ft_cube(char *map, int save)
{
	t_all	*a;
	t_data	*data;
	int		i;

	a = ft_calloc(1, sizeof(t_all));
	if (!a)
		ft_error(&a);
	a->d = ft_calloc(1, sizeof(t_data));
	if (!a->d)
		ft_error(&a);
	data = a->d;
	ft_parser(map, &a);
	i = 0;
	data->save = save;
	ft_player(&a);
	ft_init_text(&a);
	ft_mlx(&a);
	ft_clean(&a);
}

int	main(int argc, char **argv)
{
	int	len;
	int	save;

	save = 0;
	if (argc < 2 || argc > 3)
		ft_arg_error();
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
			ft_arg_error();
		save = 1;
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".cub", 5))
		ft_arg_error();
	ft_cube(argv[1], save);
	return (0);
}
