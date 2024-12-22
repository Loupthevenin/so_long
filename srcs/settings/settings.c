/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:02:51 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/22 12:06:13 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**malloc_map(const char *path, int line_count, int *column_count)
{
	char	**result;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * line_count);
	if (!result)
	{
		close(fd);
		return (NULL);
	}
	line = get_next_line(fd);
	if (line)
	{
		*column_count = ft_strlen(line) - 1;
		free(line);
	}
	close(fd);
	return (result);
}

static char	*read_map_line(int fd, int column_count)
{
	char	*line;
	char	*result;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	result = malloc(sizeof(char) * (column_count + 1));
	if (!result)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(result, line, column_count + 1);
	free(line);
	return (result);
}

static void	loop_line(char **result, int fd, int line_count, int column_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		result[i] = read_map_line(fd, column_count);
		if (!result[i])
		{
			free_map(result, i);
			return ;
		}
		i++;
	}
}

char	**get_map(const char *path, int line_count, int *column_count)
{
	char	**result;
	int		fd;

	result = malloc_map(path, line_count, column_count);
	if (!result)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(result);
		return (NULL);
	}
	loop_line(result, fd, line_count, *column_count);
	close(fd);
	return (result);
}

int	count_lines(const char *path)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 1;
	line = get_next_line(fd);
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
	close(fd);
	return (i);
}
