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

char	*join_and_free(char	*tmp_buffer, char *buffer)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(tmp_buffer, buffer);
	if (!new_buffer)
		return (NULL);
	free(tmp_buffer);
	tmp_buffer = NULL;
	return (new_buffer);
}

char	*accumulate_stash(int fd, char *stash, char	*buffer)
{
	long int	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stash)
			return (NULL);
		stash = join_and_free(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;
	size_t	size_line;

	if (!stash)
		return (NULL);
	line = ft_strchr(stash, '\n');
	if (line != NULL)
	{
		size_line = line - stash + 1;
		line = ft_calloc(size_line + 1, sizeof(char));
		if (!line)
			return (NULL);
		i = 0;
		while (i < size_line)
		{
			line[i] = stash[i];
			i++;
		}
	}
	else
		line = ft_strdup(stash);
	if (!line)
		return (NULL);
	return (line);
}

char	*extract_after_n(char *stash)
{
	char	*new_stash;
	char	*tmp;

	if (!stash)
		return (NULL);
	tmp = ft_strchr(stash, '\n');
	if (!tmp)
		return (NULL);
	new_stash = ft_strdup(tmp + 1);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char			*stash;
	char				*buffer;	
	char				*line;
	char				*tmp_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	stash = accumulate_stash(fd, stash, buffer);
	if (!stash)
	{
		free(buffer);
		return (NULL);
	}
	line = extract_line(stash);
	tmp_stash = extract_after_n(stash);
	free(stash);
	stash = tmp_stash;
	free(buffer);
	return (line);
}
