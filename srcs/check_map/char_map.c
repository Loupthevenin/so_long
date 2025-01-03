/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:50:07 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/02 17:00:01 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	char_map(char *line, int fd, t_settings *settings)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != 'E')
			error_map(line, fd, settings, "Invalid char in map\n");
		i++;
	}
}
