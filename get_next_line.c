/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:33:17 by osousa-d          #+#    #+#             */
/*   Updated: 2025/09/20 19:27:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *str, unsigned long start, size_t size)
{
	unsigned long	i;
	char			*s;
	size_t			len_s;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	len_s = ft_strlen(str) - start;
	if (len_s > size)
		len_s = size;
	s = ft_calloc(len_s + 1, sizeof(char));
	i = 0;
	while (i < len_s)
	{
		s[i] = str[start];
		start++;
		i++;
	}
	return (s);
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
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	unsigned long		i;
	char				*line;
	size_t				size_line;

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
	if (!tmp || (!*(tmp + 1)))
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
