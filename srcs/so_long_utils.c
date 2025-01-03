/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:35:48 by ltheveni          #+#    #+#             */
/*   Updated: 2025/01/02 18:59:22 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**map_dup(t_settings settings)
{
	int		i;
	char	**result;

	result = (char **)malloc(sizeof(char *) * settings.line);
	if (!result)
		return (NULL);
	i = 0;
	while (i < settings.line)
	{
		result[i] = ft_strdup(settings.map[i]);
		if (!result[i])
		{
			free_map(result, i);
			return (NULL);
		}
		i++;
	}
	return (result);
}
