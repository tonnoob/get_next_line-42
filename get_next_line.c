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

char	*extract_after_n(char *stash)
{
	int		i;
	int		j;
	int		size;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	size = ft_strlen(stash) - (i + 1);
	new_stash = ft_calloc(size + 1, sizeof(char));
	j = 0;
	while (j < size)
		new_stash[j++] = stash[i++];
	return (new_stash);
}

char	*extract_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*accumulate_stash(int fd, char *stash, char	*buffer)
{
	long unsigned int	bytes_read;
	char				*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!stash)
		{
			stash = ft_strdup("");
			if (!stash)
				return (NULL);
		}
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		tmp = NULL;
		if (ft_strchr(stash, '\n') != NULL)
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char			*stash;
	char				*buffer;	
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	stash = accumulate_stash(fd, stash, buffer);
	if (!stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = extract_after_n(stash);
	free(buffer);
	return (line);
}
