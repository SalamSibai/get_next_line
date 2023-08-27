/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:48:35 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/27 20:10:02 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// checks if there are any end line characters in the list
char *get_line(t_list *head, int end_index)
{
	char *str;
	int i;
	int size;
	i = 0;

	if (end_index <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (end_index + 2));
	// printf("end index = %i", end_index);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < end_index)
		str[i] = cpy_list(&head);
	str[i] = '\0';
	// head = head -> next;
	// printf("head content: %c\n", head->content);
	return (str);
}

char *get_next_line(int fd)
{
	char *buff;
	static t_list *head;
	int read_size;
	int pos;
	static int is_init = 0;

	read_size = 0;
	if (!is_init)
	{
		is_init = 1;
		// head = NULL;
		printf("head doesn't exist\n");
		set_list(&head);
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (free(head), NULL);
	pos = line_finder(head);
	if (pos != -1)
	{
		printf("endl exists in list\n");
		return (get_line(head, pos));
	}
	printf("passed to here\n");
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	printf("2) passed to here\n");
	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size < 0)
		return (free(buff), NULL);
	buff[read_size] = '\0';
	if (read_size > 0)
	{
		printf("read size: %d\n", read_size);
		// printf("head content_____%c\n", head ->content);
		if (push_buff(buff, &head) == 0)
		{
			printf("filled list with nothing \n");
			return (NULL);
		}
		pos = line_finder(head);
		if (pos != -1)
		{
			printf("found endl\n");
			return (get_line(head, pos));
			// break;
		}
		else
		{
			printf("line not found, read again\n");
			free(buff);
			return (get_next_line(fd));
			// read_size = read(fd, buff, BUFFER_SIZE);
			// printf("read size: %d\n", read_size);
		}
	}
	return (NULL);
	// check for endline through line finder
	//printf("will print line \n"); 
}
