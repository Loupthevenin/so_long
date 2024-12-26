/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:20:03 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/26 15:43:22 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	rect_map(char *line, int fd, t_settings *settings)
{
	if ((int)ft_strlen(line) - 1 != settings->column)
		error_map(line, fd, settings, "Rectangle only");
}

static void	wall_map(char *line, t_settings *settings, int i, int fd)
{
	int	j;

	if (i == 0 || i == settings->line - 1)
	{
		j = 0;
		while (line[j] != '\n')
		{
			if (line[j] != '1')
				error_map(line, fd, settings, "Wall");
			j++;
		}
	}
	else
	{
		if (line[0] != '1' || line[settings->column - 1] != '1')
			error_map(line, fd, settings, "Wall");
	}
}

static int	loop_check_map(t_settings *settings, int *count, const char *path)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		rect_map(line, fd, settings);
		wall_map(line, settings, i, fd);
		count_all(line, count);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

static void	check_path(t_settings *settings, const char *path)
{
	int	len_path;

	len_path = ft_strlen(path);
	if (ft_strncmp(&path[len_path - 4], ".ber", 4) != 0)
	{
		free_map(settings->map, settings->line);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(".ber file", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_map(t_settings *settings, const char *path)
{
	int	count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	check_path(settings, path);
	if (!loop_check_map(settings, count, path))
	{
		free_map(settings->map, settings->line);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("File not found", 2);
		exit(EXIT_FAILURE);
	}
	settings->collectible = count[2];
	check_count(count, settings);
}
