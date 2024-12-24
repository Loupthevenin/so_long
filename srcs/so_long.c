/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:21:07 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/24 15:49:12 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_settings	settings;

	if (argc != 2)
	{
		perror("./so_long map.ber");
		return (1);
	}
	init_settings(&settings, argv[1]);
	check_map(&settings, argv[1]);
	find_exit(&settings);
	print_map(settings.map, settings.line);
	ft_printf("============\n");
	init_mlx(&settings);
	return (0);
}
