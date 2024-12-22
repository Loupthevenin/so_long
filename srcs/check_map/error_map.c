/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:12:11 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/22 15:34:14 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	cleanup(char *line, int fd, t_settings *settings)
{
	free(line);
	if (fd >= 0)
		close(fd);
	free_map(settings->map, settings->line);
}

void	error_map(char *line, int fd, t_settings *settings, char *msg)
{
	cleanup(line, fd, settings);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
