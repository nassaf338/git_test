/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:30:28 by nassaf            #+#    #+#             */
/*   Updated: 2024/12/10 00:53:17 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_map{
	int		rows;
	int		columns;
	int		wrong_columns;
	int		total_c;
	int		total_p;
	int		total_e;
	int		actual_x;
	int		actual_y;
	char	*actual_coordin;
	char	*tail;
	char	*head;
}	t_map;

typedef struct s_coordinates{
	int		x;
	int		y;
	char	*previous;
	char	*next;
}	t_coordin;

//checking/check_map.c
int		check_if_ber(char **argv);
int		open_ber_map(int argc, char **argv);
int		check_characters(int fd);
t_map	*create_map_data(void);
void	get_map_dimensions(int fd, t_map *map_data);

//checking/check_map2.c
t_map	*check_map(int argc, char **argv);
char	*free_array(char **array, int i);
char	**alloc_mem_to_array(t_map *map_data);
char	**ber_to_array(int argc, char **argv, t_map *map_data);
int		check_border(char **array, t_map *map_data);

//checking/check_map3.c
void	count_cpe(char **array, t_map *map_data);
int		write_error(char *text, int total_char);
int		check_cpe(t_map *map_data);

//checking/check_itin.c
void	find_player(char **array, t_map *map_data);

//get_next_line
char	*append_char_to_line(char *line, char c, int len);
ssize_t	buffer_read(int fd, char *buffer, int *position, int *buf_size);
char	*read_line(int fd, char *buffer, int *position, int *buf_size);
char	*get_next_line(int fd);

#endif