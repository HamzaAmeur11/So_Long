/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:16:03 by hameur            #+#    #+#             */
/*   Updated: 2022/05/17 02:04:11 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int keycode, t_mlx *p_mlx)
{
	int		x;
	int		y;

	x = p_mlx->player.x;
	y = p_mlx->player.y;
	if (keycode == 53)
		dest(p_mlx, 1);
	else if (keycode == 13)
		up_mv(p_mlx, x, y);
	else if (keycode == 0)
		left_mv(p_mlx, x, y);
	else if (keycode == 2)
		right_mv(p_mlx, x, y);
	else if (keycode == 1)
		down_mv(p_mlx, x, y);
	return (0);
}

void	hook(t_mlx *p_mlx)
{
	mlx_hook(p_mlx->win_ptr, 17, 0, dest, p_mlx);
	mlx_hook(p_mlx->win_ptr, 2, 0, moves, p_mlx);
	mlx_loop(p_mlx->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_mlx	p_mlx;

	if (ac > 2 || ac == 1)
	{
		p_mlx.player.error = 2;
		ft_error(&p_mlx.player);
	}
	p_mlx.player.map.map_arg = av[1];
	p_mlx.player.map.fd = open(av[1], O_RDONLY);
	check_ber(&p_mlx.player);
	check_map(&p_mlx.player);
	p_mlx.mlx_ptr = mlx_init();
	p_mlx.win_ptr = mlx_new_window(p_mlx.mlx_ptr, 30 * (p_mlx.player.map.l_x
				- 1), 30 * p_mlx.player.map.l_y, (char *)"So_Long");
	put_map(&p_mlx);
	hook(&p_mlx);
	return (0);
}
