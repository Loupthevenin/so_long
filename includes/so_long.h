/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:22:24 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/02 12:05:43 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_settings
{
	int			column;
	int			line;
	int			width;
	int			height;
	int			sprite_size;
	int			collectible;
	int			exit;
	char		**map;
	int			player_x;
	int			player_y;
	int			count_move;
}				t_settings;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*wall_sprite;
	void		*floor_sprite;
	void		*collectible_sprite;
	void		*player_sprite;
	void		*exit_sprite;
}				t_mlx;

typedef struct s_game
{
	t_mlx		mlx;
	t_settings	*settings;
}				t_game;

void			free_map(char **map, int size);
char			**get_map(const char *path, int line_count, int *column_count);
int				count_lines(const char *path);
void			init_settings(t_settings *settings, const char *path);
void			error_map(char *line, int fd, t_settings *settings, char *msg);
void			count_all(char *line, int *count);
void			check_count(int *count, t_settings *settings);
void			check_map(t_settings *settings, const char *path);
void			find_exit(t_settings *settings);
void			print_map(char **map, int line_count);
void			init_sprite(t_game *game, t_settings *settings);
void			draw_map(t_mlx *mlx, t_settings *settings);
void			cleanup_sprites(t_mlx *mlx);
int				close_window(t_game *game);
int				handle_key(int key, t_game *game);
void			init_mlx(t_settings *settings);

#endif
