/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:22:24 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/22 15:36:01 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_settings
{
	int		column;
	int		line;
	int		width;
	int		height;
	char	**map;
}			t_settings;

void		free_map(char **map, int size);
char		**get_map(const char *path, int line_count, int *column_count);
int			count_lines(const char *path);
void		init_settings(t_settings *settings, const char *path);
void		error_map(char *line, int fd, t_settings *settings, char *msg);
void		count_all(char *line, int *count);
void		check_count(int *count, t_settings *settings);
void		check_map(t_settings *settings, const char *path);

#endif
