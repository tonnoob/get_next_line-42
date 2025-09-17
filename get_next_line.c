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
			stash = ft_strdup("");	
		stash = join_and_free(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
		line[j++] = '\n';
	return (line);
}

char	*extract_after_n(char *stash)
{
	unsigned long	i;
	unsigned long	j;
	size_t			size_new_stash;
	char			*new_stash;

	if (!stash)
		return (NULL);
	new_stash = ft_strchr(stash, '\n');
	size_new_stash = ft_strlen(new_stash + 1);
	new_stash = ft_calloc(size_new_stash + 2, sizeof(char));
	ft_strdup(j)
	return (new_stash)
}

// char	*extract_after_n(char *stash)
// {
// 	int				i;
// 	unsigned long	j;
// 	char			*new_stash;

// 	if (!stash)
// 		return (NULL);
// 	i = 0;
// 	while (stash[i] != '\n' && stash[i])
// 		i++;
// 	if (stash[i] == '\0')
// 	{
// 		stash = NULL;
// 		return (NULL);
// 	}
// 	new_stash = ft_calloc((ft_strlen(stash) - (i)) + 1, sizeof(char));
// 	if (!new_stash)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (j < (ft_strlen(stash) - (i)))
// 		new_stash[j++] = stash[i++];
// 	return (new_stash);
// }

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
