/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:16:06 by hameur            #+#    #+#             */
/*   Updated: 2022/05/16 21:22:35 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dest(t_mlx *p_mlx, int error)
{
	int	i;

	i = -1;
	while (p_mlx->player.map.map[++i])
		free(p_mlx->player.map.map[i]);
	free(p_mlx->player.map.map);
	mlx_destroy_window(p_mlx->mlx_ptr, p_mlx->win_ptr);
	if (error == 0)
	{
		ft_putstr_fd((char *)"Move Number:", 1);
		ft_putnbr_fd(p_mlx->player.mvs, 1);
		ft_putstr_fd((char *)"\n", 1);
		ft_putstr_fd((char *)"_____You Win_____\n", 1);
		exit(0);
	}
	exit(1);
}

void	up_mv(t_mlx *p_mlx, int x, int y)
{
	int	z;
	int	t;

	if (p_mlx->player.map.map[y - 1][x] == '0'
		|| p_mlx->player.map.map[y - 1][x] == 'C')
	{
		if (p_mlx->player.map.map[y - 1][x] == 'C')
			p_mlx->player.c -= 1;
		p_mlx->y = (y - 1) * 30;
		p_mlx->x = (x) * 30;
		put_player(p_mlx, &z, &t);
		p_mlx->y = (y) * 30;
		p_mlx->x = (x) * 30;
		put_empty(p_mlx, &z, &t);
		p_mlx->player.map.map[p_mlx->player.y][p_mlx->player.x] = '0';
		p_mlx->player.map.map[p_mlx->player.y - 1][p_mlx->player.x] = 'P';
		p_mlx->player.y -= 1;
		p_mlx->player.mvs += 1;
		ft_putstr_fd((char *)"Move Number :", 1);
		ft_putnbr_fd(p_mlx->player.mvs, 1);
		ft_putstr_fd((char *)"\n", 1);
	}
	else if (p_mlx->player.map.map[y - 1][x] == 'E' && !p_mlx->player.c)
		dest(p_mlx, 0);
}

void	down_mv(t_mlx *p_mlx, int x, int y)
{
	int	z;
	int	t;

	if (p_mlx->player.map.map[y + 1][x] == '0'
		|| p_mlx->player.map.map[y + 1][x] == 'C')
	{
		if (p_mlx->player.map.map[y + 1][x] == 'C')
			p_mlx->player.c -= 1;
		p_mlx->y = (y + 1) * 30;
		p_mlx->x = (x) * 30;
		put_player(p_mlx, &z, &t);
		p_mlx->y = (y) * 30;
		p_mlx->x = (x) * 30;
		put_empty(p_mlx, &z, &t);
		p_mlx->player.map.map[p_mlx->player.y][p_mlx->player.x] = '0';
		p_mlx->player.map.map[p_mlx->player.y + 1][p_mlx->player.x] = 'P';
		p_mlx->player.y += 1;
		p_mlx->player.mvs += 1;
		ft_putstr_fd((char *)"Move Number :", 1);
		ft_putnbr_fd(p_mlx->player.mvs, 1);
		ft_putstr_fd((char *)"\n", 1);
	}
	else if (p_mlx->player.map.map[y +1][x] == 'E' && !p_mlx->player.c)
		dest(p_mlx, 0);
}

void	left_mv(t_mlx *p_mlx, int x, int y)
{
	int	z;
	int	t;

	if (p_mlx->player.map.map[y][x - 1] == '0'
		|| p_mlx->player.map.map[y][x - 1] == 'C')
	{
		if (p_mlx->player.map.map[y][x - 1] == 'C')
			p_mlx->player.c -= 1;
		p_mlx->y = (y) * 30;
		p_mlx->x = (x - 1) * 30;
		put_player(p_mlx, &z, &t);
		p_mlx->y = (y) * 30;
		p_mlx->x = (x) * 30;
		put_empty(p_mlx, &z, &t);
		p_mlx->player.map.map[p_mlx->player.y][p_mlx->player.x] = '0';
		p_mlx->player.map.map[p_mlx->player.y][p_mlx->player.x - 1] = 'P';
		p_mlx->player.x -= 1;
		p_mlx->player.mvs += 1;
		ft_putstr_fd((char *)"Move Number :", 1);
		ft_putnbr_fd(p_mlx->player.mvs, 1);
		ft_putstr_fd((char *)"\n", 1);
	}
	else if (p_mlx->player.map.map[y][x - 1] == 'E' && !p_mlx->player.c)
		dest(p_mlx, 0);
}

void	right_mv(t_mlx *p_mlx, int x, int y)
{
	int	z;
	int	t;

	if (p_mlx->player.map.map[y][x + 1] == '0'
		|| p_mlx->player.map.map[y][x + 1] == 'C')
	{
		if (p_mlx->player.map.map[y][x + 1] == 'C')
			p_mlx->player.c -= 1;
		p_mlx->y = (y) * 30;
		p_mlx->x = (x + 1) * 30;
		put_player(p_mlx, &z, &t);
		p_mlx->y = (y) * 30;
		p_mlx->x = (x) * 30;
		put_empty(p_mlx, &z, &t);
		p_mlx->player.map.map[p_mlx->player.y][p_mlx->player.x] = '0';
		p_mlx->player.map.map[p_mlx->player.y][p_mlx->player.x + 1] = 'P';
		p_mlx->player.x += 1;
		p_mlx->player.mvs += 1;
		ft_putstr_fd((char *)"Move Number :", 1);
		ft_putnbr_fd(p_mlx->player.mvs, 1);
		ft_putstr_fd((char *)"\n", 1);
	}
	else if (p_mlx->player.map.map[y][x + 1] == 'E' && !p_mlx->player.c)
		dest(p_mlx, 0);
}
