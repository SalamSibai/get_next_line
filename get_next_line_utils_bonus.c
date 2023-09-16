/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:38:31 by ssibai            #+#    #+#             */
/*   Updated: 2023/09/10 16:04:23 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_cpy(char **cpy, char **buff, int after_reed)
{
	int	index;

	if (*cpy && after_reed == 0)
	{
		index = line_checker(*cpy, 0);
		if (index != -1 && index != -2)
			return (get_the_line(*cpy, index));
		else if (index == -2)
			return (get_end_of_file(NULL, cpy, 0));
	}
	else if (*cpy && after_reed == 1)
	{
		index = line_checker(*cpy, 1);
		if (index != -1 && index != -2)
		{
			free(*buff);
			return (get_the_line(*cpy, index));
		}
		else
			return (get_end_of_file(buff, cpy, 1));
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	line_checker(char *line, int reed)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i ++;
	}
	if (i < BUFFER_SIZE && reed == 1)
		return (-2);
	return (-1);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*copy;

	i = 0;
	if (!*src)
		return (NULL);
	copy = malloc((ft_strlen(src)+ 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;
	size_t	cctr;

	i = 0;
	if (s == NULL || start > ft_strlen(s) || s[0] == 0)
		return (ft_strdup("\0"));
	slen = ft_strlen(s);
	if (start + len < slen)
		cctr = len;
	else
		cctr = slen - (size_t) start;
	sub = malloc(cctr + 1);
	if (sub == NULL)
		return (NULL);
	while (i < cctr)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
