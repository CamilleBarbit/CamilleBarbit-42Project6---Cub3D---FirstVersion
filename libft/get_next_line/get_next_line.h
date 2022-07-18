/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:51:01 by cbarbit           #+#    #+#             */
/*   Updated: 2022/07/18 13:55:12 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdio.h>

# define BUFFER_SIZE 4

int		ft_checkendofline(char *buffer_save);
size_t	ft_strlenn(char *str);
char	*ft_print_line(char *buffer_save);
char	*ft_get_buffer_save(char *buffer_save);
char	*ft_read(int fd, char *buffer_read);
char	*get_next_line(int fd);
char	*ft_strdupp(char *src);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_substrr(char *s, unsigned int start, size_t len);
char	*ft_strchrr(char *string, int c);

#endif
