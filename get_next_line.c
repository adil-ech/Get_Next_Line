/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:21:53 by adechaji          #+#    #+#             */
/*   Updated: 2024/11/18 18:00:21 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*checker(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*ft_nextline(char *s)
{
	int		i;
	int		len;
	int		j;
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
	j = 0;
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (free(s), tmp);
}

static char	*readappend(int fd, char *buffer, char *rem)
{
	int		bread;

	bread = 1;
	while (bread > 0)
	{
		bread = read(fd, buffer, BSIZE);
		buffer[bread] = '\0';
		rem = ft_strjoin(rem, buffer);
		if (checker(rem, '\n'))
			break ;
	}
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*buffer;

	if (read(fd, NULL, 0) == -1 || BSIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BSIZE + 1));
	if (!buffer)
		return (NULL);
	rem = readappend(fd, buffer, rem);
	free(buffer);
	buffer = rem;
	buffer = ft_substr(buffer);
	rem = ft_nextline(rem);
	return (buffer);
}
