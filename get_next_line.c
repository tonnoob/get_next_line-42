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


void	free_all(t_gnl_node	*node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		next = node->next;
		free(node->stash)
	}

	if (!buffer->stash && !buffer)
	{
		free(buffer->stash);
		free()
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

char	*extract_after_n(t_gnl_node *buf)
{
	int		i;
	int		j;
	char	*new_stash;

	if (!buf || !buf->stash)
		return (NULL);
	i = 0;
	while (buf->stash[i] != '\n' && buf->stash[i])
		i++;
	j = 0;
	while (buf->stash[i] == '\n' && buf->stash[i + j]);

}
