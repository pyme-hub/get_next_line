/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkongim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:33 by kkongim           #+#    #+#             */
/*   Updated: 2022/08/24 16:50:52 by kkongim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_buffer(char *buffer)
{
	int		count;
	int		i;
	char	*next;

	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (!buffer[count])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buffer) - count++ + 1), sizeof(char));
	i = 0;
	while (buffer[count])
		next[i++] = buffer[count++];
	free(buffer);
	return (next);
}

char	*read_and_backup(int fd, char *buffer)
{
	int		readed;
	char	*s_buffer;

	readed = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	s_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (readed > 0 && !found_newline(buffer))
	{
		readed = read(fd, s_buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(s_buffer);
			return (NULL);
		}
		s_buffer[readed] = '\0';
		buffer = ft_strjoin(buffer, s_buffer);
	}
	free(s_buffer);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*new;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		new[i] = buffer[i];
		i++;
		if (buffer[i - 1] == '\n')
			break ;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_and_backup(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = next_buffer(buffer);
	return (line);
}
