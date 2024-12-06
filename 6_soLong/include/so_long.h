#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


typedef struct s_map{
	int	rows;
	int	columns;
	int	total_c;
	int	total_p;
	int	total_e;
	int	wrong_columns;
}   t_map;

//checking/check_map.c
int 	check_if_ber(char **argv); //checks if extension is .ber
int		open_ber_map(int argc, char **argv); //opens ber - returns "fd"
int		check_characters(int fd); //checks if the characters in the map are ok
t_map	*create_map_data(void); //creates the t_map that will hold map's related data
void	get_map_dimensions(int fd, t_map *map_data); //saves in map_data the dimensions of the map rows and columns - is used in check_map
t_map	*check_map(int argc, char **argv); //checks: map.ber - gets dimensions - returns map_data
char	*free_array(char **array, int i); //used in alloc_mem_to_array
char	**alloc_mem_to_array(t_map *map_data); //allocates memory to array - retturns array
char 	**ber_to_array(int argc, char **argv, t_map *map_data);
int 	check_border(char **array, t_map *map_data);
void 	count_cpe(char **array, t_map *map_data);
int 	check_cpe(char **array, t_map *map_data);

//get_next_line
char	*append_char_to_line(char *line, char c, int len);
ssize_t	buffer_read(int fd, char *buffer, int *position, int *buf_size);
char	*read_line(int fd, char *buffer, int *position, int *buf_size);
char	*get_next_line(int fd);

#endif

