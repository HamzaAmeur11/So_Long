/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:37:52 by hameur            #+#    #+#             */
/*   Updated: 2022/05/16 17:37:52 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_xpm(char c, t_mlx *p_mlx)
{
	int	x;
	int	y;

	if (c == '1')
		put_wall(p_mlx, &x, &y);
	else if (c == '0')
		put_empty(p_mlx, &x, &y);
	else if (c == 'P')
		put_player(p_mlx, &x, &y);
	else if (c == 'E')
		put_exit(p_mlx, &x, &y);
	else if (c == 'C')
		put_collect(p_mlx, &x, &y);
}

void	put_map(t_mlx *p_mlx)
{
	int	i;
	int	j;

	i = -1;
	p_mlx->x = 0;
	p_mlx->y = 0;
	while (p_mlx->player.map.map[++i] != NULL)
	{
		j = -1;
		while (p_mlx->player.map.map[i][++j] != 0)
		{
			check_xpm(p_mlx->player.map.map[i][j], p_mlx);
			p_mlx->x += 30;
		}
		p_mlx->x = 0;
		p_mlx->y += 30;
	}
}
