/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:53:28 by adechaji          #+#    #+#             */
/*   Updated: 2024/11/15 19:33:59 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extractlines(int fd, char *buffer, int bread, char **rem)
{
	char	*whline;
	char	*ptr;

	if (bread == 0 && !ft_strchr(*rem, '\n'))
	{
		whline = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
		free(buffer);
		return (whline);
	}
	ptr = ft_strchr(*rem, '\n');
	if (ptr)
	{
		whline = ft_substr(*rem, 0, ptr - *rem + 1);
		*rem = ft_substr(*rem, ptr - *rem + 1,
				ft_strlen(*rem) - (ptr - *rem + 1));
	}
	else
	{
		whline = ft_strdup(*rem);
		*rem = NULL;
	}
	free(buffer);
	return (whline);
}

char	*readappend(int fd, char *buffer, char **rem)
{
	char	*tmp;
	int		bread;

	while (!ft_strchr(*rem, '\n'))
	{
		bread = read(fd, buffer, BSIZE);
		if (bread < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bread] = '\0';
		tmp = ft_strjoin(*rem, buffer);
		free(*rem);
		*rem = tmp;
		if (bread == 0)
			break ;
	}
	return (extractlines(fd, buffer, bread, rem));
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buffer;
	char		*whline;

	if (BSIZE == 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BSIZE + 1));
	if (!buffer)
		return (NULL);
	if (!rem)
	{
		rem = ft_strdup("");
		if (!rem)
		{
			free(buffer);
			return (NULL);
		}
	}
	whline = readappend(fd, buffer, &rem);
	return (whline);
}
