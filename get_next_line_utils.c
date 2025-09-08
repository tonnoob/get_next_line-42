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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (char *)&s[i];
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	new_str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*new_str;

	i = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	size = (ft_strlen(s1) + ft_strlen(s2));
	new_str = calloc(size + 1, sizeof(char));
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (new_str);
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

char	*ft_substr(const char *s, unsigned int start, size_t size)
{
	int		i;
	int		min;
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = ft_calloc(size + 1, sizeof(char));
	if (!substr)
		return (NULL);
	min = (ft_strlen(s) - start);
	if (min > size)
		min = size;
	i = 0;
	while (i < min)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	return (substr);
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
