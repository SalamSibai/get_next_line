/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:32:33 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/29 20:57:48 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	get next line:

	input							process								output
	----->|																|----->
	file																line
			1) char *buff;
			2) read into buffer
			3) look for endl within buffer
			4) if exists, copy till endl to a str (that will be returned)
			5) otherwise, copy to a string that will later be joined with buffer
			6) at the end of each iteration, free the buffer
			7) a pointer should be static, that points to the list that 
			has the copied characters (till the newline obviously)


			cases:
			1) cpy is not empty, and contains a line still
			2) cpy has no new line, so it copies to the buffer again
				a. if that buffer has a new line, it strjoins the existing cpy, with
				what's in the buffer (till the new line), copies the rest to the cpy,
				then frees buffer.
				b. if the buffer doesn't have a new line, it str joins everything to cpy,
				then frees buffer.
*/

#include "get_next_line.h"


	// int		i = 0;
	// char	*str;
	// char	*start_pointer;

	// str = (char *)malloc(sizeof(char) * (index + 1));
	// if (!str)
	// 	return (NULL);
	// if (from_buff == 0)
	// {
	// 	while (i < index)
	// 	{
	// 		str[i] = cpy [i];
	// 		i++;
	// 	}
	// 	str [i] = '\0';
	// }
	// return str;
char	*get_next_line(int fd)
{
	static char	*cpy;
	char		*buff;
	char		*str;
	int			read_size;
	int			index;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (free(cpy), NULL);
	if (cpy)
	{
		index = line_checker(cpy);
		if (index != -1)
			return (get_line(cpy, index));
	}
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size < 0)
		return (free(buff), NULL);
	buff[read_size] = '\0';
	while (read_size > 0)
	{
		index = line_checker(buff);
		if (index == -1)
		{
			store_buffer(buff, cpy, BUFFER_SIZE);
			free(buff);
		}
		else
		{
			
		}
	}

	return (str);
}