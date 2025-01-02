/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:21:07 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/02 12:14:38 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv, char **env)
{
	t_settings	settings;

	if (!env)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("env error\n", 2);
		return (1);
	}
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("./so_long map.ber", 2);
		return (1);
	}
	init_settings(&settings, argv[1]);
	check_map(&settings, argv[1]);
	find_exit(&settings);
	init_mlx(&settings);
	return (0);
}
