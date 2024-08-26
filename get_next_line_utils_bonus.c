/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 10:22:10 by mpicheca          #+#    #+#             */
/*   Updated: 2023/04/01 10:32:00 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t memb, size_t size)
{
	char		*res;
	size_t		i;

	i = 0;
	if (memb == 0 || size == 0)
		res = malloc(sizeof(char));
	else
		res = (char *)malloc(memb * size);
	if (!res)
		return (NULL);
	while (i < (memb * size))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*newstr;

	newstr = ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	i = -1;
	while (str1[++i])
		newstr[i] = str1[i];
	j = 0;
	while (str2[j])
		newstr[i++] = str2[j++];
	newstr[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (newstr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	if (!str1)
	{
		str1 = (char *)ft_calloc(1, sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2 || (str1[0] == '\0' && str2[0] == '\0'))
	{
		free(str1);
		free(str2);
		return (NULL);
	}
	return (ft_strjoin2(str1, str2));
}

char	*ft_strchr(char *buff, int n)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	if (n == '\0')
		return ((char *)&buff[ft_strlen(buff)]);
	while (buff[i])
	{
		if (buff[i] == (char) n)
			return ((char *)&buff[i]);
		i++;
	}
	return (0);
}
