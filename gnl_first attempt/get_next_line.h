/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:49:40 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/29 20:08:17 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	cpy_list(t_list **head);
int		line_finder(t_list *head);
// int		fill_list(char *buff, t_list *head);
int		push_buff(char *buff, t_list **head);
void	set_list(t_list **head);
char	*get_line(t_list *head, int end_index);

#endif