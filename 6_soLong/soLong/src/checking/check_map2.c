/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:53:35 by nassaf            #+#    #+#             */
/*   Updated: 2024/12/10 00:51:59 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*check_map(int argc, char **argv)
{
	int		fd;
	t_map	*map_data;

	check_if_ber(argv);
	fd = open_ber_map(argc, argv);
	check_characters(fd);
	lseek(fd, 0, SEEK_SET);
	map_data = create_map_data();
	get_map_dimensions(fd, map_data);
	if (map_data->columns <= map_data->rows)
	{
		write(1, "not rectangular\n", 16);
		free(map_data);
		close(fd);
		exit(1);
	}
	if (map_data->wrong_columns == 1)
	{
		write(1, "unequal rows\n", 13);
		free(map_data);
		close(fd);
		exit(1);
	}
	close(fd);
	return (map_data);
}

char	*free_array(char **array, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return (NULL);
}

char	**alloc_mem_to_array(t_map *map_data)
{
	int		i;
	char	**array;

	i = 0;
	array = (char **)malloc(map_data->rows * sizeof(char *));
	if (array == NULL)
	{
		write(1, "Array memory allocation failed\n", 31);
		return (NULL);
	}
	while (i < map_data->rows)
	{
		array[i] = (char *)malloc(map_data->columns * sizeof(char));
		if (array[i] == NULL)
		{
			write (1, "Row memory allocation failed\n", 29);
			free_array(array, i);
			exit (1);
		}
		i++;
	}
	return (array);
}

char	**ber_to_array(int argc, char **argv, t_map *map_data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**array;

	i = 0;
	fd = open_ber_map(argc, argv);
	array = alloc_mem_to_array(map_data);
	while (i < map_data->rows)
	{
		j = 0;
		line = get_next_line(fd);
		if (!line)
			free_array(array, i);
		while (j < map_data->columns && line[j] && line[j] != '\n')
		{
			array[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
	close(fd);
	return (array);
}

int	check_border(char **array, t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_data->columns)
	{
		if (array[0][i] != '1' || array[map_data->rows - 1][i] != '1')
		{
			write(1, "Wrong Borders\n", 14);
			return (0);
		}
		i++;
	}
	j = 0;
	while (j < map_data->rows)
	{
		if (array[j][0] != '1' || array[j][map_data->columns - 1] != '1')
		{
			write(1, "Wrong Borders\n", 14);
			return (0);
		}
		j++;
	}
	return (1);
}
