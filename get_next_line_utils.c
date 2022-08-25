/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkongim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:22:22 by kkongim           #+#    #+#             */
/*   Updated: 2022/03/27 23:23:17 by kkongim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(char *current)
{
	int		i;

	if (!current)
		return (0);
	i = 0;
	while (current[i])
	{
		if (current[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		count;
	int		len;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	len = 0;
	if (!join || !s1 || !s2)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		join[len++] = s1[count++];
	}
	count = 0;
	while (s2[count])
	{
		join[len++] = s2[count++];
	}
	join[len] = '\0';
	free(s1);
	return (join);
}
