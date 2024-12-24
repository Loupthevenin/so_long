/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:03:35 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/24 16:03:10 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_settings(t_settings *settings, const char *path)
{
	settings->line = count_lines(path);
	settings->map = get_map(path, settings->line, &settings->column);
	settings->sprite_size = 32;
	settings->width = settings->sprite_size * settings->column;
	settings->height = settings->sprite_size * settings->line;
	settings->exit = 0;
}
