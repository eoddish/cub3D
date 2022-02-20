/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:30:51 by eoddish           #+#    #+#             */
/*   Updated: 2021/04/28 01:47:14 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE_H
# define FT_CUBE_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"

typedef struct s_rf
{
	int		r;
	int		g;
	int		b;
}			t_rf;

typedef struct s_rc
{
	int		r;
	int		g;
	int		b;
}			t_rc;

typedef struct s_spr
{
	struct s_spr	*next;
	int				x;
	int				y;
}		t_spr;

typedef struct s_data
{
	int		save;
	int		x;
	int		y;
	t_rc	*rc;
	t_rf	*rf;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	**map;
	t_spr	*spr;
}			t_data;

typedef struct s_img
{
	void	*img;
	int		img_w;
	int		img_h;
	char	*adr;
	int		bpp;
	int		len;
	int		end;
}			t_img;

typedef struct s_mdata
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_w;
	int		img_h;
	char	*adr;
	int		bpp;
	int		len;
	int		end;
	int		key;
	int		x;
	int		y;
}			t_mdata;

typedef struct s_plr
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}			t_plr;

typedef struct s_sput
{
	float		sprceil;
	float		sprheight;
	float		sprwidth;
	float		lx;
	float		ly;
	float		fov;
}			t_sput;

typedef struct s_gnl
{
	char	*buf;
	char	prev[1];
	int		off;
	t_list	*lst;
	int		flag;
}		t_gnl;

typedef struct s_all
{
	t_img	*no;
	t_img	*so;
	t_img	*ea;
	t_img	*we;
	t_img	*t;
	t_img	*s;
	t_img	*put;
	t_mdata	*m;
	t_data	*d;
	t_plr	*p;
	t_sput	*sput;
	int		f;
	int		c;
	float	eyex;
	float	eyey;
	int		testx;
	int		testy;
	t_gnl	*g;
	int		stepx;
	int		stepy;
	float	raylenx;
	float	rayleny;
	char	*str1;
	char	*str2;
}			t_all;

void			ftg_bzero(void *s, size_t n);
int				get_next_line(int fd, char **line, t_gnl *g);
int				ftg_create_list(t_list **lst, void *content);
void			ftg_lstclear(t_list **lst, void (*del)(void*));
void			ftg_strncpy(char *dst, char *src, int n);
int				has_newline(char *buf, int n);
void			ft_parser(char *map, t_all **all);
void			ft_parse_c(t_all **all, char *line);
void			ft_parse_f(t_all **all, char *line);
void			ft_parse_s(t_all **all, char *line);
void			ft_parse_ea(t_all **all, char *line);
void			ft_parse_we(t_all **all, char *line);
void			ft_parse_no(t_all **all, char *line);
void			ft_parse_so(t_all **all, char *line);
void			ft_parse_r(t_all **all, char *line);
void			ft_error(t_all **all);
void			ft_clean(t_all **all);
void			ft_mapcheck(t_all **all, char **map);
void			ft_mlx(t_all **all);
void			ft_player(t_all **all);
float			ft_ray_cast(t_all **all, float fov, int i);
int				ft_maze(t_all **all);
int				key_hook(int keycode, t_all **all);
void			ft_image(t_all **all);
void			ft_put_pixel(t_all **all, int x, int y, int col);
int				ft_quit(t_all **all);
int				ft_draw_spr(t_all **all, float spritex,
					float spritey, float *depth);
int				key_released(int keycode, t_all **all);
t_spr			*ft_sort_spr(t_all *a, t_spr *s);
int				ft_rgb(int r, int g, int b);
void			ft_save(t_all **all);
void			ft_move_plr(t_all **all);
void			ft_draw_wall(t_all **all, int ceil, float samplex, int i);
void			ft_parse_spr(t_data **data, char **map);
void			ft_init_text(t_all **all);
int				check_line(char *line);
void			ft_col_error(t_all **all, char ***n);
#endif
