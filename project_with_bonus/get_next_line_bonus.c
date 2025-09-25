/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:05:00 by osousa-d          #+#    #+#             */
/*   Updated: 2025/09/22 20:05:08 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *str, unsigned long start, size_t size)
{
	unsigned long	i;
	char			*s;
	size_t			len_s;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
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
		{
			free(stash);
			return (NULL);
		}
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
	char	*line;
	char	*pos_n;
	size_t	size_line;

	if (!stash)
		return (NULL);
	pos_n = ft_strchr(stash, '\n');
	if (pos_n == NULL)
	{
		line = ft_strdup(stash);
		if (!line)
			return (NULL);
	}
	else
	{
		size_line = (pos_n - stash) + 1;
		line = ft_substr(stash, 0, size_line);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*extract_after_n(char *stash)
{
	char	*new_stash;
	char	*pos_n;

	if (!stash)
		return (NULL);
	pos_n = ft_strchr(stash, '\n');
	if (!pos_n || (!*(pos_n + 1)))
		return (NULL);
	new_stash = ft_strdup(pos_n + 1);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char			*stash[MAX_FD];
	char				*buffer;	
	char				*line;
	char				*tmp_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	stash[fd] = accumulate_stash(fd, stash[fd], buffer);
	if (!stash[fd])
	{
		free(buffer);
		return (NULL);
	}
	line = extract_line(stash[fd]);
	tmp_stash = extract_after_n(stash[fd]);
	free(stash[fd]);
	stash[fd] = tmp_stash;
	free(buffer);
	return (line);
}
