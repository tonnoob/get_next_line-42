#include "get_next_line.h"

int	print_file(char	*file)
{
	int		fd;
	int		bytes_read;
	char	buffer[32];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	bytes_read = read(fd, buffer, 32);
	if (bytes_read == 0)
		return (0);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, 32);
	}
	close(fd);
	return (0);
}

char	*read_all(char *file)
{
	int		fd;
	int		bytes_read;
	char	buffer[33];
	char	*final_str;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return	(NULL);

	final_str = ft_calloc(1, 1);
	bytes_read = read(fd, buffer, 32);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(final_str, buffer);
		free(final_str);
		final_str = temp;
		bytes_read = read(fd, buffer, 32);
	}
	close(fd);
	return (final_str);
}

int	main(void)
{
	print_file("readme.txt");
	return (0);
}
