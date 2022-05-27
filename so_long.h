/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:15:58 by hameur            #+#    #+#             */
/*   Updated: 2022/05/19 15:06:27 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

typedef struct t_map
{
	char	**map;
	char	*map_arg;
	int		l_x;
	int		l_y;
	int		fd;
}	t_map;

typedef struct t_player
{
	int		x;
	int		y;
	int		e;
	int		c;
	int		p;
	int		mvs;
	int		error;
	t_map	map;
}	t_player;

typedef struct p_mlx
{
	int			x;
	int			y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_player	player;
}	t_mlx;

void	read_map(t_map *map);
void	zero(t_player *player);
void	count_lines(t_map *map);
void	check_map(t_player *player);
void	check_char(t_player *player, char *str, int y);
void	ft_error(t_player *player);
void	put_wall(t_mlx *mlx, int *x, int *y);
void	put_collect(t_mlx *mlx, int *x, int *y);
void	put_empty(t_mlx *mlx, int *x, int *y);
void	put_player(t_mlx *mlx, int *x, int *y);
void	put_exit(t_mlx *mlx, int *x, int *y);
void	put_map(t_mlx *p_mlx);
void	check_xpm(char c, t_mlx *p_mlx);
int		dest(t_mlx *p_mlx, int error);
void	hook(t_mlx *p_mlx);
int		moves(int keycode, t_mlx *p_mlx);
void	left_mv(t_mlx *p_mlx, int x, int y);
void	right_mv(t_mlx *p_mlx, int x, int y);
void	left_mv(t_mlx *p_mlx, int x, int y);
void	down_mv(t_mlx *p_mlx, int x, int y);
void	up_mv(t_mlx *p_mlx, int x, int y);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	check_ber(t_player *player);

#endif