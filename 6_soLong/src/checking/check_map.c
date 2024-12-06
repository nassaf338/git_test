/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nic <Nic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:49:13 by Nic               #+#    #+#             */
/*   Updated: 2024/12/02 18:11:46 by Nic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_if_ber(char **argv)
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
		return(0);
	write(1, "wrong map format\n", 17);
	exit(1);
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
	return(fd);
}
int	check_characters(int fd)
{
	char	c;
	int		read_bytes;

	while ((read_bytes = read(fd, &c, 1)) > 0)
	{
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n')
		{
			write(1, "wrong characters\n", 16);
			exit(1);
		}	
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
	return(map);
}
void	get_map_dimensions(int fd, t_map *map_data)
{
	char	c;
	int		i;
	int		read_bytes;
	
	i = 0;
	while ((read_bytes = read(fd, &c, 1)) > 0)
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
	}
	if (i > 0)
	{
		map_data->rows++;
		if (i != map_data->columns)
			map_data->wrong_columns++;
	}
}
t_map	*check_map(int argc, char **argv)
{
	int	fd;
	t_map	*map_data;

	check_if_ber(argv);
	fd = open_ber_map(argc, argv);
	check_characters(fd);
	lseek(fd, 0, SEEK_SET);
	map_data = create_map_data();
	get_map_dimensions(fd, map_data);
	if(map_data->columns <= map_data->rows)
	{
		write(1, "not rectangular\n", 16);
		free(map_data);
		close(fd);
		exit(1);
	}
	if(map_data->wrong_columns == 1)
	{
		write(1, "unequal rows\n", 13);
		free(map_data);
		close(fd);
		exit(1);
	}
	close(fd);
	return(map_data);
}
//used in "char **alloc_mem_to_array" to free the array in case of error in allocating memory for rows (because function took more than 25 lines)
char	*free_array(char **array, int i)
{
	int j;
	
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
	int i;
	char **array;
	
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
	return(array);
}
char **ber_to_array(int argc, char **argv, t_map *map_data)
{
    int i;
    int fd;
    char *line;
    char **array;

    i = 0;
    fd = open_ber_map(argc, argv);
    array = alloc_mem_to_array(map_data);
    while (i < map_data->rows)
    {
        line = get_next_line(fd);
        if (!line)
        {
            close(fd);
			free_array(array, i);
        }
        int j = 0;
        while (j < map_data->columns && line[j] && line[j] != '\n')
        {
            array[i][j] = line[j];
            j++;
        }
        free(line);  // Free the original line after copying
        i++;
    }
    close(fd);
    return(array);
}
int check_border(char **array, t_map *map_data)
{
    int i;
    int j;

    i = 0;
	j = 0;
    while (i < map_data->columns)
    {
        if (array[0][i] != '1' || array[map_data->rows - 1][i] != '1')
        {
            write(1, "Wrong Borders\n", 14);
            return(0);
        }
        i++;
    }
    j = 0;
    while (j < map_data->rows)
    {
        if (array[j][0] != '1' || array[j][map_data->columns - 1] != '1')
        {
            write(1, "Wrong Borders\n", 14);
            return(0);
        }
        j++;
    }
	return(1);
}
void count_cpe(char **array, t_map *map_data)
{
    int i;
    int j;
    
    // Reset counters to ensure accurate counting
    map_data->total_c = 0;
    map_data->total_p = 0;
    map_data->total_e = 0;
    
    j = 0;
    while (j < map_data->rows)
    {
        i = 0;  // Initialize i inside the outer loop
        while (i < map_data->columns)
        {
            if (array[j][i] == 'C')  // Use == for comparison, not ===
                map_data->total_c++;
            if (array[j][i] == 'P')
                map_data->total_p++;
            if (array[j][i] == 'E')
                map_data->total_e++;  // Corrected to increment total_e, not total_c
            i++;
        }
        j++;
    }
}

int check_cpe(char **array, t_map *map_data)
{
    if (map_data->total_p != 1)
    {
        write(1, "More than 1 player\n", 19);  // Write to stderr
        free_array(array);
        close(fd);
        return (0);
    }
    if (map_data->total_e != 1)
    {
        write(1, "More than 1 exit\n", 17);  // Write to stderr
        free_array(array);
        close(fd);
        return (0);
    }
    if (map_data->total_c < 1)
    {
        write(1, "No collectibles\n", 16);  // Write to stderr
        free_array(array);
        close(fd);
        return (0);
    }
    return (1);
}