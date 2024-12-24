/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:59:35 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/24 16:32:34 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	cleanup_sprites(t_mlx *mlx)
{
	if (mlx->wall_sprite)
		mlx_destroy_image(mlx->mlx, mlx->wall_sprite);
	if (mlx->player_sprite)
		mlx_destroy_image(mlx->mlx, mlx->player_sprite);
	if (mlx->exit_sprite)
		mlx_destroy_image(mlx->mlx, mlx->exit_sprite);
	if (mlx->collectible_sprite)
		mlx_destroy_image(mlx->mlx, mlx->collectible_sprite);
}

int	close_window(t_game *game)
{
	cleanup_sprites(&game->mlx);
	free_map(game->settings->map, game->settings->line);
	exit(EXIT_FAILURE);
}

void	init_mlx(t_settings *settings)
{
	t_game	game;

	game.settings = settings;
	game.mlx.mlx = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.mlx, settings->width,
			settings->height, "so_long");
	init_sprite(&game.mlx, settings);
	draw_map(&game.mlx, settings);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx.mlx);
}
