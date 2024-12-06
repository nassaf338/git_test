
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
