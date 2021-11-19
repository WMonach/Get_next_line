/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:17:07 by wmonacho          #+#    #+#             */
/*   Updated: 2021/11/19 19:53:52 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"
#include <limits.h>

int	ft_real_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static int	ft_add_alloc(char **buffer)
{
	char	*tmp;
	int		j;
	int		i;

	j = 0;
	tmp = *buffer;
	*buffer = ft_calloc(BUFFER_SIZE + ft_strlen(*buffer, '\0') + 1, 1);
	if (!*buffer)
	{
		free(tmp);
		return (-1);
	}
	i = ft_strlen(tmp, '\0');
	if (!tmp)
		return (0);
	while (tmp[j])
	{
		(*buffer)[j] = tmp[j];
		j++;
	}
	free(tmp);
	return (i);
}

static char	*ft_realloc(char **buffer)
{
	char	*temp;
	char	*line;
	int		i;
	int		j;

	temp = *buffer;
	i = ft_real_strlen(temp);
	*buffer = ft_calloc(ft_strlen(temp, '\0') + 1, 1);
	line = ft_calloc(i + 2, 1);
	if (!line || !*buffer)
	{
		free(temp);
		return (NULL);
	}
	i = -1;
	while (temp[++i] != '\n' && temp[i] != '\0')
		line[i] = temp[i];
	line[i] = temp[i];
	i = 0;
	j = ft_real_strlen(temp) + 1;
	while (temp[j] != '\0')
		(*buffer)[i++] = temp[j++];
	free(temp);
	return (line);
}

static char	*ft_read(int fd, char **buffer)
{
	int				i;
	char			*cest_une_connerie;

	i = 0;
	cest_une_connerie = NULL;
	while (i == 0)
	{
		if (ft_strchr(*buffer, '\n'))
			return (ft_realloc(buffer));
		i = ft_add_alloc(buffer);
		i = read(fd, *buffer + i, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		if (i == 0)
		{
			if (ft_strlen(*buffer, '\0') == 0)
				return (NULL);
			return (ft_realloc(buffer));
		}
		if (ft_strchr(*buffer, '\n'))
			return (ft_realloc(buffer));
		i = 0;
	}
	return (cest_une_connerie);
}

char	*get_next_line(int fd)
{
	static char		*buffer[OPEN_MAX];
	char			*line;

	line = ft_read(fd, &buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
