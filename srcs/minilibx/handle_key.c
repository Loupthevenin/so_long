/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:27:05 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/26 11:49:19 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	press_keys(int key, int *new_x, int *new_y, t_game *game)
{
	if (key == 13)
	{
		*new_y -= 1;
		return (1);
	}
	else if (key == 1)
	{
		*new_y += 1;
		return (1);
	}
	else if (key == 0)
	{
		*new_x -= 1;
		return (1);
	}
	else if (key == 2)
	{
		*new_x += 1;
		return (1);
	}
	else if (key == 53)
		close_window(game);
	return (0);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	t_settings	*settings;

	settings = game->settings;
	if (game->settings->map[new_y][new_x] != '1')
	{
		settings->map[settings->player_y][settings->player_x] = '0';
		settings->map[new_y][new_x] = 'P';
		settings->player_x = new_x;
		settings->player_y = new_y;
		draw_map(&game->mlx, settings);
	}
}

int	handle_key(int key, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->settings->player_x;
	new_y = game->settings->player_y;
	if (press_keys(key, &new_x, &new_y, game))
	{
		game->settings->count_move += 1;
		ft_printf("Le nombre de mouvement du joueur est de : %d\n",
			game->settings->count_move);
	}
	move_player(game, new_x, new_y);
	return (0);
}
