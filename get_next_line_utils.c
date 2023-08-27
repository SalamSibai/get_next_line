/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:49:28 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/27 20:00:57 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	this function is to initialize the list
	returns true if list was set
*/
void set_list(t_list **head)
{
	*head = (t_list *)malloc(sizeof(t_list));
	if (!*head)
		return;
	(*head)->content = 0;
	(*head)->next = NULL;
}

/*
	this function is to fill the list with the buffer characters
	the buffer must be freed after the list is filled (character by character)
*/

int push_buff(char *buff, t_list **head)
{
	t_list *temp;
	t_list *new;

	if (!buff || !*head)
		return (0);
	if ((*head)->next == NULL)
	{
		(*head)->content = *buff;
		buff++;
	}
	temp = *head;
	while (temp && temp->next != NULL)
		temp = temp->next;
	printf("buff first char %c\n", *buff);
	while (*buff)
	{
		printf("Entering buff safely %c\n", *buff);
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (0);
		temp->next = new;
		new->content = *buff;
		temp = new;
		new->next = NULL;
		buff++;
	}

	return (1);
}

int fill_list(char *buff, t_list *head)
{
	t_list *temp;

	if (buff == NULL)
		return (0);
	temp = head;
	while (*buff)
	{
		temp->content = *buff;
		temp->next = (t_list *)malloc(sizeof(t_list));
		temp = temp->next;
		if (!temp)
			return (0);
		buff++;
	}
	// free (temp);
	// temp = NULL;
	return (1);
}

/*
	checks for a \n in the list:
	returns the index which has the \n character:
	1) returns 0 if the list is empty
	2) returns length when endline is found OR when temp is != null
*/
int line_finder(t_list *head)
{
	printf("finding line \n");
	t_list *iterator;
	int i;
	// printf("--%c--\n", head ->content);
	i = 0;
	if (head == NULL || head->next == NULL)
	{
		printf("head is bye bye\n");
		return (-1);
	}
	iterator = head;
	if (!iterator->content)
		return (-1);
	while (iterator)
	{
		printf("iterator content:{%c}\n", iterator->content);

		if (iterator->content == '\n')
		{
			printf("___%d___\n", i);
			return (i);
		}
		i++;
		// printf("what\n");
		iterator = iterator->next;
	}
	return (-1);
}

/*
	reads from list and pops that character out of the list
*/
char cpy_list(t_list **head)
{
	char c;
	t_list *temp;
	temp = *head;
	c = (*head)->content;
	(*head) = (*head)->next;
	free(temp);
	temp = NULL;
	return c;
}
