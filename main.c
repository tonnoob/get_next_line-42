#include "get_next_line.h"
#include <stdio.h>

int	main()
{	
	int		fd;
	char	*line;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (line = get_next_line(fd))
	{	
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
