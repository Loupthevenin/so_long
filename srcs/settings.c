/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:02:51 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/20 22:27:38 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_size(const char *path, t_settings *settings)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	i = 1;
	line = get_next_line(fd);
	settings->column = ft_strlen(line) - 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
		i++;
	}
	settings->line = i;
	close(fd);
}

void	init_settings(t_settings *settings, const char *path)
{
	get_size(path, settings);
	settings->width = settings->column * 64;
	settings->height = settings->line * 64;
}
