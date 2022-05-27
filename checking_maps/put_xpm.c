/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:54:04 by hameur            #+#    #+#             */
/*   Updated: 2022/05/16 00:37:52 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall(t_mlx *p_mlx, int *x, int *y)
{
	p_mlx->img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr,
			(char *)"xpm/1.xpm", x, y);
	mlx_put_image_to_window(p_mlx->mlx_ptr, p_mlx->win_ptr, p_mlx->img_ptr,
		p_mlx->x, p_mlx->y);
}

void	put_empty(t_mlx *p_mlx, int *x, int *y)
{
	p_mlx->img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr,
			(char *)"xpm/0.xpm", x, y);
	mlx_put_image_to_window(p_mlx->mlx_ptr,
		p_mlx->win_ptr, p_mlx->img_ptr, p_mlx->x, p_mlx->y);
}

void	put_collect(t_mlx *p_mlx, int *x, int *y)
{
	put_empty(p_mlx, x, y);
	p_mlx->img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr,
			(char *)"xpm/c.xpm", x, y);
	mlx_put_image_to_window(p_mlx->mlx_ptr, p_mlx->win_ptr, p_mlx->img_ptr,
		p_mlx->x, p_mlx->y);
}

void	put_player(t_mlx *p_mlx, int *x, int *y)
{
	put_empty(p_mlx, x, y);
	p_mlx->img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr,
			(char *)"xpm/p.xpm", x, y);
	mlx_put_image_to_window(p_mlx->mlx_ptr, p_mlx->win_ptr, p_mlx->img_ptr,
		p_mlx->x, p_mlx->y);
}

void	put_exit(t_mlx *p_mlx, int *x, int *y)
{
	put_empty(p_mlx, x, y);
	p_mlx->img_ptr = mlx_xpm_file_to_image(p_mlx->mlx_ptr,
			(char *)"xpm/e.xpm", x, y);
	mlx_put_image_to_window(p_mlx->mlx_ptr, p_mlx->win_ptr, p_mlx->img_ptr,
		p_mlx->x, p_mlx->y);
}
