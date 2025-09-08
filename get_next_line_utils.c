/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:33:47 by osousa-d          #+#    #+#             */
/*   Updated: 2025/08/29 18:33:50 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_chr(const char *s, char c, int *pos)
{
	int		i;

	i = 0;
	if (pos)
		*pos = -1;
	while (s[i])
	{
		if (s[i] == c && *pos == -1)
			*pos = i;
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int				i;
	unsigned char	*p;
	void			*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen_chr(s1 ? s1 : "", '\0', NULL);
	size_s2 = ft_strlen_chr(s2 ? s2 : "", '\0', NULL);
	str = ft_calloc(size_s1 + size_s2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		str[i] = s1 ? s1[i] : '\0';
		i++;
	}
	j = 0;
	while (j < size_s2)
		str[i++] = s2 ? s2[j++] : '\0';
	free(s1);
	return (str);
}

char	*extract_after_n(t_gnl_node *buf)
{
	int		i;
	int		j;
	size_t	size;
	char	*new_stash;

	if (!buf || !buf->stash)
		return (NULL);
	i = 0;
	while (buf->stash[i] != '\n' && buf->stash[i])
		i++;
	if (buf->stash[i] == '\0')
	{
		free(buf->stash);
		buf->stash = NULL;
		return (NULL);
	}
	size = ft_strlen(buf->stash) - (i + 1);
	new_stash = ft_calloc(size + 1, sizeof(char));
	j = 0;
	while (j < size)
		new_stash[j++] = buf->stash[i++];
	return (new_stash);
}

char	*extract_line(t_gnl_node *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buf || !buf->stash)
		return (NULL);
	while (buf->stash[i] && buf->stash[i] != '\n')
		i++;
	if (buf->stash[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	j = 0;
	while (j < i)
	{
		line[j] = buf->stash[j];
		j++;
	}
	if (buf->stash[i] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}
