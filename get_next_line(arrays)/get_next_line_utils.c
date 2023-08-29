/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:46:29 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/29 20:58:09 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_checker(char *line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (line[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

char *get_line(char *cpy, int index)
{
	int		i = 0;
	char	*str;
	char	*start_pointer;

	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	while (i < index)
	{
		str[i] = cpy [i];
		i++;
	}
	str [i] = '\0';
	return str;
}

void store_buffer(char *buff, char *cpy, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		cpy[i] = buff[i];
		i ++;
	}
}