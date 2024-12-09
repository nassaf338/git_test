/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:17:44 by nassaf            #+#    #+#             */
/*   Updated: 2024/12/10 00:47:26 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_cpe(char **array, t_map *map_data)
{
	int	i;
	int	j;

	map_data->total_c = 0;
	map_data->total_p = 0;
	map_data->total_e = 0;
	j = 1;
	while (j < map_data->rows - 1)
	{
		i = 1;
		while (i < map_data->columns - 1)
		{
			if (array[j][i] == 'C')
				map_data->total_c++;
			if (array[j][i] == 'P')
				map_data->total_p++;
			if (array[j][i] == 'E')
				map_data->total_e++;
			i++;
		}
		j++;
	}
}

int	write_error(char *text, int total_char)
{
	write (1, text, total_char);
	return (0);
}

int	check_cpe(t_map *map_data)
{
	if (map_data->total_p > 1)
		write_error("More than 1 player\n", 19);
	if (map_data->total_e > 1)
		write_error("More than 1 exit\n", 17);
	if (map_data->total_p < 1)
		write_error("No player\n", 10);
	if (map_data->total_e < 1)
		write_error("No exit\n", 8);
	if (map_data->total_c < 1)
		write_error("No collectibles\n", 16);
	return (1);
}
