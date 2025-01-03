/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:27:05 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/03 11:02:17 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	press_keys(int key, int *new_x, int *new_y, t_game *game)
{
	if (key == 119)
	{
		*new_y -= 1;
		return (1);
	}
	else if (key == 115)
	{
		*new_y += 1;
		return (1);
	}
	else if (key == 97)
	{
		*new_x -= 1;
		return (1);
	}
	else if (key == 100)
	{
		*new_x += 1;
		return (1);
	}
	else if (key == 65307)
		close_window(game, EXIT_SUCCESS);
	return (0);
}

static void	set_value(t_game *game, int new_x, int new_y)
{
	game->settings->map[new_y][new_x] = 'P';
	game->settings->player_x = new_x;
	game->settings->player_y = new_y;
	game->settings->count_move += 1;
	ft_printf("Le nombre de mouvement du joueur est de : %d\n",
		game->settings->count_move);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	t_settings	*settings;
	int			is_exit;

	settings = game->settings;
	is_exit = 0;
	if (settings->map[new_y][new_x] != '1')
	{
		if (settings->map[new_y][new_x] == 'C')
			settings->collectible--;
		if (settings->map[new_y][new_x] == 'E' && settings->collectible == 0)
			is_exit = 1;
		if (settings->exit)
		{
			settings->map[settings->player_y][settings->player_x] = 'E';
			settings->exit = 0;
		}
		else
			settings->map[settings->player_y][settings->player_x] = '0';
		if (settings->map[new_y][new_x] == 'E')
			settings->exit = 1;
		set_value(game, new_x, new_y);
		draw_map(&game->mlx, settings);
	}
	if (is_exit)
		close_window(game, EXIT_SUCCESS);
}

int	handle_key(int key, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->settings->player_x;
	new_y = game->settings->player_y;
	if (press_keys(key, &new_x, &new_y, game))
		move_player(game, new_x, new_y);
	return (0);
}
