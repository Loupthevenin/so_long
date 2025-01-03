/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:59:35 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/03 11:51:41 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	error_mlx(t_game *game, char *mess)
{
	ft_putstr_fd(mess, 2);
	if (game->mlx.mlx)
		mlx_destroy_display(game->mlx.mlx);
	if (game->mlx.mlx)
		free(game->mlx.mlx);
	free_map(game->settings->map, game->settings->line);
	exit(EXIT_FAILURE);
}

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
	if (mlx->floor_sprite)
		mlx_destroy_image(mlx->mlx, mlx->floor_sprite);
}

int	close_window(t_game *game, int status)
{
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
	exit(status);
}

void	init_mlx(t_settings *settings)
{
	t_game	game;

	game.settings = settings;
	game.mlx.mlx = mlx_init();
	if (!game.mlx.mlx)
		error_mlx(&game, "Error\nmlx init\n");
	game.mlx.win = mlx_new_window(game.mlx.mlx, settings->width,
			settings->height, "so_long");
	if (!game.mlx.win)
	{
		mlx_destroy_window(game.mlx.mlx, game.mlx.win);
		error_mlx(&game, "Error\nmlx window\n");
	}
	init_sprite(&game, settings);
	draw_map(&game.mlx, settings);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_key_hook(game.mlx.win, handle_key, &game);
	mlx_loop(game.mlx.mlx);
	close_window(&game, EXIT_SUCCESS);
}
