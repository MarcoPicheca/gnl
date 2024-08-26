/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:37:41 by mpicheca          #+#    #+#             */
/*   Updated: 2023/03/14 16:37:42 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t memb, size_t size);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *buff, int n);

#endif
