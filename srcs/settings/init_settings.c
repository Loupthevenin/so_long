/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:03:35 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/26 11:28:47 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	player_pos(t_settings *settings)
{
	int	i;
	int	j;

	i = 0;
	while (i < settings->line)
	{
		j = 0;
		while (j < settings->column)
		{
			if (settings->map[i][j] == 'P')
			{
				settings->player_x = j;
				settings->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_settings(t_settings *settings, const char *path)
{
	settings->line = count_lines(path);
	settings->map = get_map(path, settings->line, &settings->column);
	settings->sprite_size = 32;
	settings->width = settings->sprite_size * settings->column;
	settings->height = settings->sprite_size * settings->line;
	settings->exit = 0;
	player_pos(settings);
	settings->count_move = 0;
}
