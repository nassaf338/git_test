/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:42:43 by nassaf            #+#    #+#             */
/*   Updated: 2024/12/07 01:53:32 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_if_ber(char **argv)
{
	int	i;

	i = 0;
	if (!argv[1])
		return (1);
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] == 'r'
			&& argv[1][i - 2] == 'e'
			&& argv[1][i - 3] == 'b'
			&& argv[1][i - 4] == '.')
		return (0);
	write(1, "wrong map format\n", 17);
	exit (1);
}

int	open_ber_map(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "many arguments\n", 16);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error Opening Map: ");
		exit(1);
	}
	return (fd);
}

int	check_characters(int fd)
{
	char	c;
	int		read_bytes;

	read_bytes = read(fd, &c, 1);
	while (read_bytes > 0)
	{
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P'
			&& c != '\n')
		{
			write(1, "wrong characters\n", 16);
			exit(1);
		}	
		read_bytes = read(fd, &c, 1);
	}
	if (read_bytes == -1)
	{
		write(1, "read error\n", 11);
		exit(1);
	}
	return (0);
}

t_map	*create_map_data(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		write(1, "allocation failed\n", 18);
		exit(1);
	}
	map->rows = 0;
	map->columns = 0;
	map->wrong_columns = 0;
	map->total_c = 0;
	map->total_p = 0;
	map->total_e = 0;
	return (map);
}

void	get_map_dimensions(int fd, t_map *map_data)
{
	char	c;
	int		i;
	int		read_bytes;

	i = 0;
	read_bytes = read(fd, &c, 1);
	while (read_bytes > 0)
	{
		i++;
		if (c == '\n')
		{
			map_data->rows++;
			if (map_data->rows == 1)
				map_data->columns = i - 1;
			if (i - 1 != map_data->columns)
				map_data->wrong_columns++;
			i = 0;
		}
		read_bytes = read(fd, &c, 1);
	}
	if (i > 0)
		map_data->rows++;
	if (i != map_data->columns)
		map_data->wrong_columns++;
}
