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
	char				*line;
	char				*buffer;	
	t_gnl_node			*current;
	size_t				bytes_read;
 
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = get_node(&head, fd);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		current->stash = ft_strjoin(current->stash, buffer);
		if (ft_strchr(current->stash, '\n') != NULL)
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	line = extract_line(current);
	tmp = extract_after_n(current);
	free(current->stash);
	current->stash = tmp;
	free(buffer);
	return (line);
}

t_gnl_node *get_node(t_gnl_node **head, int fd)
{
	t_gnl_node	*current;

	if (!fd)
		return (NULL);
	if (!*head)
	{
		*head = create_node(fd);
		return (*head);
	}
	current = *head;
	while (current->fd != fd && current->next)
		current = current->next;
	if (current->fd == fd)
		return (current);
	current->next = create_node(fd);
	return (current->next);
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
