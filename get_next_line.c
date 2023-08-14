/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:48:35 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/14 23:14:17 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//checks if there are any end line characters in the list
char	*get_line(t_list *head)
{
	char	*str;
	int		endl_pos;
	int		i;
	int		size;

	i = 0;
	endl_pos = line_finder(head);
	if (endl_pos == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (endl_pos + 2));
	if (!str)
		return (NULL);
	while (i < endl_pos)
		str[i++] = cpy_list(&head);
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static t_list	*head;
	static int	initalized;
	int			read_size;
	int			pos;

	if (!initalized || !head)
		initalized = set_list(&head);
	if (!initalized || BUFFER_SIZE <= 0)
		return (free(head), NULL);
	pos = 0;
	if (line_finder(head) != -1)
		return (get_line(head));
	buff =(char *) malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	//check if the list has been initialized or filled
	//look for a line in the list
	read_size = read(fd, buff, 	BUFFER_SIZE);
	// while (read_size > 0 && line_finder(head) != -1)
	//check if the list is not empty, and if there are lines
	buff[read_size] = '\0';
	if (read_size > 0)
	{
		//set the linked list;
		if (fill_list(buff, head) == 0)
			return (NULL); 
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	//check for endline through line finder
	return (get_line(head));
}
