/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:48:35 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/26 16:44:55 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//checks if there are any end line characters in the list
char	*get_line(t_list *head, int end_index)
{
	char	*str;
	//int		endl_pos;
	int		i;
	int		size;

	i = 0;
	//endl_pos = line_finder(head);
	if (end_index == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (end_index + 2));
	if (!str)
		return (NULL);
	while (i < end_index)
		str[i++] = cpy_list(&head);
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static t_list	*head;
	int				read_size;
	int				pos;

	printf("called function\n");
	//check if the list has been initialized or filled
	if (!head)
		set_list(&head);
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (free(head), NULL);
	pos = line_finder(&head);
	//look for a line in the list
	if (pos != -1)
	{
		printf("listExists\n");
		return (get_line(head, pos));
	}
	buff =(char *) malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!buff)
	{
		printf("no space for buffer \n");
		return (NULL);
	}
	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size < 0)
	{
		return (free(buff),NULL);
	}
	// while (read_size > 0 && line_finder(head) != -1)
	// check if the list is not empty, and if there are lines
	buff[read_size] = '\0';
	while (read_size > 0)
	{
		//set the linked list;
		if (fill_list(buff, head) == 0)
		{
			printf("filled list with nothing \n");
			return (NULL);
		}
		pos = line_finder(&head);
		if (pos != -1)
			break;
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	//check for endline through line finder
	printf("will print line \n");
	return (get_line(head, pos));
}
