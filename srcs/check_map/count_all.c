/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:37:27 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/22 15:37:47 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	count_all(char *line, int *count)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'E')
			count[0]++;
		else if (line[i] == 'P')
			count[1]++;
		else if (line[i] == 'C')
			count[2]++;
		i++;
	}
}

void	check_count(int *count, t_settings *settings)
{
	if (count[0] != 1 || count[1] != 1 || count[2] < 1)
	{
		free_map(settings->map, settings->line);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("1 P, 1 E, 1 C", 2);
		exit(EXIT_FAILURE);
	}
}
