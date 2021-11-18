/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:34:12 by wmonacho          #+#    #+#             */
/*   Updated: 2021/11/18 14:03:37 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*ft_calloc(int elementCount, int elementSize)
{
	int			count;
	char		*dest;

	count = 0;
	dest = malloc(elementCount * elementSize);
	if (dest == NULL)
		return (NULL);
	while (count < elementCount * elementSize)
	{
		dest[count] = '\0';
		count++;
	}
	return (dest);
}

char	*ft_strchr(char *string, int searchedChar)
{
	int	count;

	count = 0;
	if (!string)
		return (NULL);
	while (string[count] != '\0')
	{
		if (string[count] == (char)searchedChar)
			return ((char *)string + count);
		count++;
	}
	if (string[count] == (char)searchedChar)
		return ((char *)string + count);
	return (NULL);
}

int	ft_strlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c)
		i++;
	return (i);
}
