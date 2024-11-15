/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:53:28 by adechaji          #+#    #+#             */
/*   Updated: 2024/11/14 19:35:58 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buffer;
	char		*tmp;
	char		*ptr;
	char		*whline;
	int			bread;

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
	while (!ft_strchr(rem, '\n'))
	{
		bread = read(fd, buffer, BSIZE);
		if (bread < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bread] = '\0';
		tmp = ft_strjoin(rem, buffer);
		free(rem);
		rem = tmp;
		if (bread == 0)
			break;
	}
	if (bread == 0 && !ft_strchr(rem, '\n'))
	{
		free(buffer);
		return (NULL);
	}
	ptr = ft_strchr(rem, '\n');
	if (ptr)
	{
		whline = ft_substr(rem, 0, ptr - rem + 1);
		rem = ft_substr(rem, ptr - rem + 1, ft_strlen(rem) - (ptr - rem + 1));
	}
	else
	{
		whline = ft_strdup(rem);
		rem = NULL;
	}
	free(buffer);
	return (whline);
}
