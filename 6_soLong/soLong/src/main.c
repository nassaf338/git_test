/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:37:32 by nassaf            #+#    #+#             */
/*   Updated: 2024/12/09 23:57:56 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map_data;
	char	**array;

	if (argc != 2)
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	map_data = check_map(argc, argv);
	array = ber_to_array(argc, argv, map_data);
	count_cpe(array, map_data);
	find_player(array, map_data);
	printf("rows: %d\n", map_data->rows);
	printf("columns: %d\n", map_data->columns);
	printf("total_c: %d\n", map_data->total_c);
	printf("total_p: %d\n", map_data->total_p);
	printf("total_e: %d\n", map_data->total_e);
	printf("PLayer X: %d\n", map_data->actual_x);
	printf("Player Y: %d\n", map_data->actual_y);
	printf("wrong_columns: %d\n\n", map_data->wrong_columns);
	check_border(array, map_data);
	check_cpe(map_data);
	free_array(array, map_data->rows);
	free(map_data);
}
