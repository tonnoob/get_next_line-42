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
		{
			free(stash);
			stash = NULL;
			break ;
		}
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");	
		stash = join_and_free(stash, buffer);
		if (ft_strchr(stash, '\n') != NULL)
			break ;
	}
	return (stash);
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
	if (buffer[i] && buffer[i] == '\n')
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
	return (line);
}

char	*extract_after_n(char *stash)
{
	int		i;
	int		j;
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
	new_stash = ft_calloc((ft_strlen(stash) - (i + 1)) + 1, sizeof(char));
	if (!new_stash)
		return (NULL);
	j = 0;
	while (j < ft_strlen(stash) - (i + 1))
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
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
		free(buffer);
		return (NULL);
	}
	line = extract_line(stash);
	stash = extract_after_n(stash);
	free(buffer);
	return (line);
}
