/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:32:03 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/02 12:09:19 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	*load_xpm(t_game *game, char *path, int img_width, int img_height)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx.mlx, path, &img_width, &img_height);
	if (!img)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("XPM file error\n", 2);
		cleanup_sprites(&game->mlx);
		if (game->mlx.win)
		{
			mlx_clear_window(game->mlx.mlx, game->mlx.win);
			mlx_destroy_window(game->mlx.mlx, game->mlx.win);
		}
		if (game->mlx.mlx)
			mlx_destroy_display(game->mlx.mlx);
		if (game->mlx.mlx)
			free(game->mlx.mlx);
		free_map(game->settings->map, game->settings->line);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	init_sprite(t_game *game, t_settings *settings)
{
	game->mlx.floor_sprite = load_xpm(game, "assets/floor.xpm",
			settings->sprite_size, settings->sprite_size);
	game->mlx.wall_sprite = load_xpm(game, "assets/wall.xpm",
			settings->sprite_size, settings->sprite_size);
	game->mlx.exit_sprite = load_xpm(game, "assets/exit.xpm",
			settings->sprite_size, settings->sprite_size);
	game->mlx.player_sprite = load_xpm(game, "assets/player.xpm",
			settings->sprite_size, settings->sprite_size);
	game->mlx.collectible_sprite = load_xpm(game, "assets/collectible.xpm",
			settings->sprite_size, settings->sprite_size);
}
