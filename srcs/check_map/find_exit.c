/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:46:28 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/03 11:28:01 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	find_player(t_settings settings, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < settings.line)
	{
		j = 0;
		while (j < settings.column)
		{
			if (settings.map[i][j] == 'P')
			{
				if (!flag)
					return (i);
				else
					return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	flood_fill(int x, int y, char **map, t_settings *settings)
{
	if (x < 0 || y < 0 || x >= settings->line || y >= settings->column)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'E')
		settings->exit = 1;
	if (map[x][y] == 'C')
		settings->collectible--;
	map[x][y] = 'V';
	flood_fill(x + 1, y, map, settings);
	flood_fill(x - 1, y, map, settings);
	flood_fill(x, y + 1, map, settings);
	flood_fill(x, y - 1, map, settings);
}

static void	cleanup(t_settings *settings, char **map_cpy, char *mess)
{
	free_map(map_cpy, settings->line);
	free_map(settings->map, settings->line);
	ft_putstr_fd(mess, 2);
	exit(EXIT_FAILURE);
}

void	find_exit(t_settings *settings)
{
	int		player_x;
	int		player_y;
	char	**map_cpy;
	int		collectible;

	player_x = find_player(*settings, 0);
	player_y = find_player(*settings, 1);
	collectible = settings->collectible;
	map_cpy = map_dup(*settings);
	if (!map_cpy)
		cleanup(settings, map_cpy, "Error\nAllocation failed\n");
	flood_fill(player_x, player_y, map_cpy, settings);
	if (settings->exit == 0 || settings->collectible != 0)
		cleanup(settings, map_cpy, "Error\nInvalid path map\n");
	settings->collectible = collectible;
	settings->exit = 0;
	free_map(map_cpy, settings->line);
}
