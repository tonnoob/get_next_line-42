/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:33:17 by osousa-d          #+#    #+#             */
/*   Updated: 2025/08/29 18:33:20 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	free_all(char *buffer, char *buf)
{
	char	*temp;

	if (buffer && *buffer)
	{
		free(*buffer);
		buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	t_gnl_node	*new_node;
	char	*buffer;
	char	*stash;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read(fd, buffer, BUFFER_SIZE);
	new_node = ft_calloc(sizeof(t_gnl_node));
	if (!new_node)
		return (NULL);
	
}

char	*return_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!stash)
	{
		line = ft_strdup("");
		return (line);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] = '\n')
	{
		line[i] = '\n';
		j++;
	}
	line[j] = '\0'; 
	return (line);
}

// jhkjasghd\n
//          i