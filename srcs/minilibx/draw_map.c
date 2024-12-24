/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:28:20 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/24 16:21:11 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	put_image(t_mlx *mlx, t_settings *settings, int i, int j)
{
	int	x;
	int	y;

	x = j * settings->sprite_size;
	y = i * settings->sprite_size;
	if (settings->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall_sprite, x, y);
	else if (settings->map[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player_sprite, x, y);
	else if (settings->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collectible_sprite, x,
				y);
	else if (settings->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit_sprite, x, y);
}

void	draw_map(t_mlx *mlx, t_settings *settings)
{
	int	i;
	int	j;

	i = 0;
	while (i < settings->line)
	{
		j = 0;
		while (j < settings->column)
		{
			put_image(mlx, settings, i, j);
			j++;
		}
		i++;
	}
}
