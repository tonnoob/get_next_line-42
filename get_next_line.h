/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:33:32 by osousa-d          #+#    #+#             */
/*   Updated: 2025/08/29 18:33:33 by osousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

typedef struct s_gnl_node
{
	int					fd;
	char				*stash;
	struct s_gnl_node	*next;
}	t_gnl_node;

char	*extract_line(t_gnl_node *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_after_n(t_gnl_node *buf);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen_chr(const char *s, char c, int *pos);

#endif