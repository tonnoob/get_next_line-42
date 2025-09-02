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


void	free_all(char *stash, char *buffer)
{
	if (stash && *stash)
	{
		free(*stash);
		stash = NULL;
	}
	if (buffer && *buffer)
	{
		free(*buffer);
		buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	t_gnl_node	*new_node;

	
	new_node = ft_calloc(sizeof(t_gnl_node));
	if (!new_node)
		return (NULL);
}