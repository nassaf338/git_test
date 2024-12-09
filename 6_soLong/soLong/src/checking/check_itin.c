/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_itin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:22:09 by nassaf            #+#    #+#             */
/*   Updated: 2024/12/10 00:22:48 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player(char **array, t_map *map_data)
{
	int	x;
	int	y;

	y = 1;
	while (y < map_data->rows - 1)
	{
		x = 1;
		while (x < map_data->columns)
		{
			if (array[y][x] == 'P')
			{
				map_data->actual_x = x;
				map_data->actual_y = y;
			}
			x++;
		}
		y++;
	}
}
