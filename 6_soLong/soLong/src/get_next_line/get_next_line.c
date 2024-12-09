/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:36:44 by nassaf            #+#    #+#             */
/*   Updated: 2024/12/06 23:36:48 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	position = 0;
	static int	buf_size = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_line(fd, buffer, &position, &buf_size));
}
