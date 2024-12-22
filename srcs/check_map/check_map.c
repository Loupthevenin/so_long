/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:20:03 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/22 12:00:58 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	rect_map(char *line, t_settings settings)
{
	if ((int)ft_strlen(line) - 1 != settings.column)
		error_map(line, "Rectangle only");
}

static void	wall_map(char *line, t_settings settings, int i)
{
	int	j;

	if (i == 0 || i == settings.line - 1)
	{
		j = 0;
		while (line[j] != '\n')
		{
			if (line[j] != '1')
				error_map(line, "Wall");
			j++;
		}
	}
	else
	{
		if (line[0] != '1' || line[settings.column - 1] != '1')
			error_map(line, "Wall");
	}
}

static int	*loop_check_map(t_settings settings, int *count, const char *path)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (count);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		rect_map(line, settings);
		wall_map(line, settings, i);
		count_all(line, count);
		free(line);
		i++;
	}
	close(fd);
	return (count);
}

void	check_map(t_settings settings, const char *path)
{
	int	count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	loop_check_map(settings, count, path);
	check_count(count);
}
