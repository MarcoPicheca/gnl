/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 10:22:00 by mpicheca          #+#    #+#             */
/*   Updated: 2023/04/01 10:22:02 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	ft_bzero(void *res, size_t memb_size);
void	*ft_calloc(size_t memb, size_t size);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *buff, int n);

#endif