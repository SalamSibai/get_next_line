/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:48:35 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/10 22:38:49 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buff[BUFF_SIZE + 1];
	static	char *line[FD_SIZE];
	
	read(fd, buff, BUFF_SIZE);
}