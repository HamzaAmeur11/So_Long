/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:40:36 by hameur            #+#    #+#             */
/*   Updated: 2022/05/16 21:24:38 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_lines(t_map *map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		free(line);
		map->l_y++;
	}
	close(map->fd);
}

void	read_map(t_map *map)
{
	int	i;

	i = 0;
	map->l_y = 0;
	count_lines(map);
	if (map->l_y == 0)
	{
		ft_putstr_fd((char *)"map incorrect", 1);
		exit(1);
	}
	map->map = (char **)malloc(sizeof(char **) * (map->l_y + 1));
	map->fd = open(map->map_arg, O_RDONLY);
	while (i <= map->l_y)
	{
		map->map[i] = get_next_line(map->fd);
		if (map->map[i] == NULL)
			break ;
		i++;
	}
	close(map->fd);
	map->l_x = ft_strlen(map->map[0]);
}
