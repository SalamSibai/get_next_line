/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:38:26 by ssibai            #+#    #+#             */
/*   Updated: 2023/09/10 16:10:20 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*store_buffer(char *buff, char *cpy, int size, size_t j)
{
	size_t	i;
	char	*temp;

	i = -1;
	if (cpy)
	{
		j = ft_strlen(cpy);
		temp = cpy;
		cpy = malloc((size_t)size + j + 1);
		if (!cpy)
			return (free(cpy), NULL);
		while (temp [++i] != '\0')
			cpy[i] = temp[i];
		free (temp);
	}
	else
	{
		cpy = malloc((size_t)size + 1);
		if (!cpy)
			return (free(cpy), NULL);
	}
	i = 0;
	while ((int)i < size + 1)
		cpy[j++] = buff[i++];
	return (cpy);
}

char	*get_the_line(char *cpy, int index)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	str = malloc (index + 2);
	if (!str)
		return (NULL);
	temp = ft_substr(cpy, index + 1, ft_strlen(cpy));
	while (i < index + 1)
	{
		str[i] = cpy[i];
		i++;
	}
	str [i] = '\0';
	i = 0;
	while (temp[i] != '\0')
	{
		cpy[i] = temp[i];
		i++;
	}
	cpy [i] = '\0';
	free (temp);
	return (str);
}

/*
	VERY STUPID FUNCTION: MAIN REASON: MAKING NORM WORK :)
	But really, the process is very repetitive so why not use a function instead?
	free_buff: whether or not buff should be freed in that specific point of time
	Uses strdup in order to get the line inside cpy, whether we read or not
	this process is helpful when we reach the end of the file
*/
char	*get_end_of_file(char **buff, char **cpy, int free_buff)
{
	char	*str;

	str = NULL;
	if (free_buff == 1)
	{
		str = ft_strdup(*cpy);
		free (*cpy);
		*cpy = NULL;
		free(*buff);
		*buff = NULL;
		return (str);
	}
	else if (free_buff == 0)
	{
		str = ft_strdup(*cpy);
		free (cpy);
		cpy = NULL;
		return (str);
	}
	return (NULL);
}
/*
	A MUCH DUMMER FUNCTION, BARE WITH ME
	the read functionality, and what it fills in.

	when index == -1: we did not read a newline in the file
	when index == -2: we reached the end of the file
	any other number: the index where the newline was found
*/

char	*reed(char *buff, char **cpy, int fd, int read_size)
{
	char	*str;
	int		index;

	str = NULL;
	index = 0;
	while (read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size <= 0)
		{
			str = check_cpy(cpy, &buff, 1);
			if (!str)
				return (free(buff), NULL);
			return (str);
		}
		buff[read_size] = '\0';
		*cpy = store_buffer(buff, *cpy, BUFFER_SIZE, 0);
		index = line_checker(*cpy, 1);
		if (index == -2)
			return (get_end_of_file(&buff, cpy, 1));
		if (index != -1)
			return (free(buff), get_the_line(*cpy, index));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*cpy[FD_SETSIZE];
	struct s_vars	v;

	v = (struct s_vars){NULL, NULL, 0};
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, v.buff, 0) < 0)
	{
		if (cpy[fd])
			free(cpy[fd]);
		cpy[fd] = NULL;
		return (NULL);
	}
	v.str = check_cpy(&cpy[fd], &v.buff, 0);
	if (v.str)
		return (v.str);
	v.buff = malloc(BUFFER_SIZE + 1);
	if (!v.buff)
		return (NULL);
	v.str = reed(v.buff, &cpy[fd], fd, 1);
	if (cpy[fd] && ft_strlen(cpy[fd]) == 0)
	{
		free(cpy[fd]);
		cpy[fd] = NULL;
	}
	return (v.str);
}
