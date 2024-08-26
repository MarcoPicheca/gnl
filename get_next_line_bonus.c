/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 10:21:46 by mpicheca          #+#    #+#             */
/*   Updated: 2023/04/01 10:33:19 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[4096];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd] == NULL || buffer[fd][0] == '\0')
		return (NULL);
	line = cut_line(buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}

int main()
{
	int fd_0 = open("./prova0.txt", O_RDONLY);
	int fd_1 = open("./prova1.txt", O_RDONLY);
	int fd_2 = open("./prova2.txt", O_RDONLY);
	int fd_3 = open("./prova3.txt", O_RDONLY);

	char *s = get_next_line(fd_0);
	char *s1 = get_next_line(fd_1);
	char *s2 = get_next_line(fd_2);
	char *s3 = get_next_line(fd_3);

	while(s != NULL || s1 != NULL || s2 != NULL || s3 != NULL)
	{
		printf(" sono zero: %s\n", s);
		free(s);
		s = get_next_line(fd_0);
		printf(" sono uno: %s\n", s1);
		free(s1);
		s1 = get_next_line(fd_1);
		printf(" sono due: %s\n", s2);
		free(s2);
		s2 = get_next_line(fd_2);
		printf(" sono tre: %s\n", s3);
		free(s3);
		s3 = get_next_line(fd_3);
	}
	printf(" ultima 0: %s\n", s);
	free(s);
	printf(" ultima 1: %s\n", s1);
	free(s1);
	printf(" ultima 2: %s\n", s2);
	free(s2);
	printf(" ultima 3: %s\n", s3);
	free(s3);
	return 0;
}
