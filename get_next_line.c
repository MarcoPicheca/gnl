/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <mpicheca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:37:33 by mpicheca          #+#    #+#             */
/*   Updated: 2023/10/17 15:45:04 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_line(char *buffer)
{
	char		*s;
	size_t		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	s = ft_calloc(i + 2, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		s[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		s[i] = buffer[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*next_line(char *buffer)
{
	char		*s;
	size_t		j;
	size_t		t;

	t = 0;
	while (buffer[t] && buffer[t] != '\n')
		t++;
	if (!buffer[t])
	{
		free(buffer);
		return (NULL);
	}
	s = ft_calloc((ft_strlen(buffer) - t) + 1, sizeof(char));
	if (!s)
		return (NULL);
	t++;
	j = 0;
	while (buffer[t])
		s[j++] = buffer[t++];
	s[j] = '\0';
	free(buffer);
	return (s);
}

int	read_2(int i, char *tmp, char *buffer)
{
	if (i == -1)
	{
		free(tmp);
		free(buffer);
		return (0);
	}
	return (1);
}

char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		i;

	tmp = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (0);
	i = 1;
	while (!ft_strchr(buffer, '\n') && i != 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (read_2(i, tmp, buffer) == 0)
			return (NULL);
		tmp[i] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (buffer == NULL)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer || buffer == NULL || buffer[0] == '\0')
		return (NULL);
	line = cut_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
