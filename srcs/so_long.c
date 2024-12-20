/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:21:07 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/20 20:24:59 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	t_settings	settings;

	if (argc != 2)
	{
		perror("./so_long map.ber");
		return (1);
	}
	init_settings(&settings, argv[1]);
	check_map(settings, argv[1]);
	mlx = mlx_init();
	mlx_new_window(mlx, settings.width, settings.height, "so_long");
	mlx_loop(mlx);
	return (0);
}
