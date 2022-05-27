/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:40:42 by hameur            #+#    #+#             */
/*   Updated: 2022/05/18 16:34:52 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_ber(t_player *player)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)".ber";
	i = 0;
	j = 0 ;
	while (player->map.map_arg[j] != '.' && player->map.map_arg[j] != '\0')
		j++;
	while (str[i] == player->map.map_arg[j])
	{
		i++;
		j++;
		if (str[i] == '\0' || player->map.map_arg[j] == '\0')
			break ;
	}
	if (player->map.map_arg[j] != '\0')
	{
		ft_putstr_fd((char *)"map must be .ber\n", 1);
		exit(1);
	}
}

void	ft_error(t_player *player)
{
	if (player->p != 1 || player->e == 0
		|| player->c == 0 || player->error == 1
		|| player->error == 2)
	{
		if (player->error == 1)
			ft_putstr_fd((char *)"map incorrect", 1);
		else if (player->error == 2)
			ft_putstr_fd((char *)"error f les argument", 1);
		else if (player->e == 1)
			ft_putstr_fd((char *)"error map <probleme f E>", 1);
		else if (player->c == 0)
			ft_putstr_fd((char *)"error map <problemef C", 1);
		else
			ft_putstr_fd((char *)"error map <probleme f P>", 1);
		exit(0);
	}
}

void	zero(t_player *player)
{
	player->mvs = 0;
	player->c = 0;
	player->e = 0;
	player->p = 0;
	player->x = 0;
	player->y = 0;
}

void	check_char(t_player *player, char *str, int y)
{
	int	x;

	x = 0;
	if (y == 1)
		zero(player);
	while (x < player->map.l_x - 1)
	{
		if (str[x] == 'P')
		{
			player->x = x ;
			player->y = y;
			player->p += 1;
		}
		else if (str[x] == 'E')
			player->e += 1;
		else if (str[x] == 'C')
			player->c += 1;
		if (str[x] != '0' && str[x] != '1')
		{
			if (str[x] != 'P' && str[x] != 'C' && str[x] != 'E')
				return (player->error = 1, ft_error(player));
		}
		x++;
	}	
}

void	check_map(t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	read_map(&player->map);
	while (player->map.map[0][x] == '1'
		&& player->map.map[player->map.l_y - 1][x] == '1')
		x++;
	if (x != player->map.l_x - 1 || x >= 87)
		return (player->error = 1, ft_error(player));
	while (player->map.map[y][0] == '1'
		&& player->map.map[y][player->map.l_x - 2] == '1'
		&& y < player->map.l_y - 1)
	{
		if (player->map.map[y][player->map.l_x - 1] != '\n')
			return (player->error = 1, ft_error(player));
		check_char(player, player->map.map[y], y);
		if (player->map.map[y + 1] == 0)
			break ;
		y++;
	}
	if (y != player->map.l_y - 1)
		return (player->error = 1, ft_error(player));
	ft_error(player);
}
