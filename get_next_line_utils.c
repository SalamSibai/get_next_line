/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:49:28 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/13 19:15:00 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	this function is to initialize the list
	returns true if list was set
*/
int	set_list(t_list *head)
{
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (0);
	return (1);
}

/*
	this function is to fill the list with the buffer characters
	the buffer must be freed after the list is filled (character by character)
*/
int	fill_list(char *buff, t_list *head)
{
	t_list	*temp;

	if (buff == NULL)
		return (0);
	temp = head;
	while (*buff)
	{
		temp -> content = *buff;
		temp -> next = (t_list *)malloc(sizeof(t_list));
		temp = temp -> next;
		buff++;
	}
	free (temp);
	temp = NULL;
	return (1);
}

/*
	checks for a \n in the list:
	returns the index which has the \n character:
	1) returns 0 if the list is empty
	2) returns length when endline is found OR when temp is != null
*/
int	line_finder(t_list *head)
{
	t_list	*iterator;
	t_list	*temp;
	int		i;

	i = 0;
	iterator = head;
	while (iterator)
	{
		if (iterator -> content == '\n')
			return (i);
		i++;
		temp = iterator;
		iterator = iterator -> next;
		free (temp);
	}
	return (-1);
}

/*
	reads from list and pops that character out of the list
*/
char	cpy_list(t_list *head)
{
	char	c;
	t_list	*temp;
	
	temp = head;
	c = head -> content;
	head = head -> next;
	free (temp);
	temp = NULL;
	return	c;
}

