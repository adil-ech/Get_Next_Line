/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:53:00 by adechaji          #+#    #+#             */
/*   Updated: 2024/11/19 02:12:01 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	t_list	*listforbonus(t_list **list, int fd)
{
	t_list	*node;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->rem = NULL;
	node->next = *list;
	*list = node;
	return (node);
}

static char	*ft_nextline(char *s)
{
	int		i;
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	len = ft_strlen(s) - i;
	tmp = malloc(len + 1);
	if (!tmp)
		return (free(s), NULL);
	i++;
	len = 0;
	while (s[i])
		tmp[len++] = s[i++];
	tmp[len] = '\0';
	free(s);
	return (tmp);
}

static void	remfree(char **rem)
{
	if (rem && *rem)
	{
		free(*rem);
		*rem = NULL;
	}
}

static char	*readappend(int fd, char *buffer, char *rem)
{
	int	bread;
	int	i;

	bread = 1;
	while (bread > 0)
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == -1)
		{
			remfree(&rem);
			break ;
		}
		buffer[bread] = '\0';
		rem = ft_strjoin(rem, buffer);
		i = 0;
		while (rem && rem[i])
		{
			if (rem[i] == '\n')
				return (rem);
			i++;
		}
	}
	return (rem);
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	t_list			*node;
	char			*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = listforbonus(&head, fd);
	if (!node)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	node->rem = readappend(fd, buffer, node->rem);
	free(buffer);
	if (!node->rem || !*node->rem)
		return (remfree(&node->rem), NULL);
	line = ft_substr(node->rem);
	node->rem = ft_nextline(node->rem);
	return (line);
}
