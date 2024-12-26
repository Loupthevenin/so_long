/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:32:03 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/24 20:35:40 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	*load_xpm(t_mlx *mlx, char *path, int img_width, int img_height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &img_width, &img_height);
	return (img);
}

void	init_sprite(t_mlx *mlx, t_settings *settings)
{
	mlx->floor_sprite = load_xpm(mlx, "assets/floor.xpm", settings->sprite_size,
			settings->sprite_size);
	mlx->wall_sprite = load_xpm(mlx, "assets/wall.xpm", settings->sprite_size,
			settings->sprite_size);
	mlx->exit_sprite = load_xpm(mlx, "assets/exit.xpm", settings->sprite_size,
			settings->sprite_size);
	mlx->player_sprite = load_xpm(mlx, "assets/player.xpm",
			settings->sprite_size, settings->sprite_size);
	mlx->collectible_sprite = load_xpm(mlx, "assets/collectible.xpm",
			settings->sprite_size, settings->sprite_size);
}
