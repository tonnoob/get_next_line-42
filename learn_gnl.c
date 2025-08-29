#include <unistd.h>
#include <fcntl.h>

int	read_file(char	*file)
{
	int		fd;
	int		bytes_read;
	char	buffer[32];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	bytes_read = read(fd, buffer, 32);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, 32);
	}
	close(fd);
	return (0);
}

int	main(void)
{
	read_file("readme.txt");
	return (0);
}
