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

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		count++;
	}	
	return (count);
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
	char	*strcat;
	size_t	total_size;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	total_size = (ft_strlen(s1) + ft_strlen(s2));
	strcat = (char *)ft_calloc(total_size + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		strcat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strcat[i + j] = s2[j];
		j++;
	}
	return (strcat);
}

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	size;
	char	*new_str;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	new_str = ft_calloc(size + 1, sizeof(char));
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c =='\0')
		return ((char *)&s[i]);
	return (NULL);
}
