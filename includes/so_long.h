/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:22:24 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/21 16:15:54 by ltheveni         ###   ########.fr       */
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
	int	column;
	int	line;
	int	width;
	int	height;
}		t_settings;

void	error_map(char *line, char *msg);
void	count_all(char *line, int *count);
void	check_count(int *count);
void	init_settings(t_settings *settings, const char *path);
void	check_map(t_settings settings, const char *path);

#endif
