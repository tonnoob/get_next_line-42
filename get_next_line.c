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

char	*get_next_line(int fd)
{
	static t_gnl_node	*head;
	char				*buffer;	
	t_gnl_node			*current;
	size_t				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
		head = create_node(fd);
	current = head;
	while (current->fd != fd && current->next)
		current = current->next;
	if (current->fd != fd)
	{
		current->next = create_node(fd);
		current = current->next;
	}

		
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

t_gnl_node	*create_node(int fd)
{
	t_gnl_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_gnl_node));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->stash = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	free_all(t_gnl_node	*node)
{
	t_gnl_node	*addr_next;

	while (node != NULL)
	{
		addr_next = node->next;
		free(node->stash);
		free(node);
		node = addr_next;
	}
}
