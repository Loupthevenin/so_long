/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:03:35 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/22 12:05:42 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_settings(t_settings *settings, const char *path)
{
	settings->line = count_lines(path);
	settings->map = get_map(path, settings->line, &settings->column);
	settings->width = settings->column * 64;
	settings->height = settings->line * 64;
}
