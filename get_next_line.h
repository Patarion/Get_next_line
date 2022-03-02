/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:11:34 by jgagnon           #+#    #+#             */
/*   Updated: 2022/01/30 17:00:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char  *get_next_line(int fd);
char  *ft_bufdup(const char *s);
int ft_strlen(const char * str);
char	*ft_strconcatenate(const char *s1, const char *s2);
char	*ft_subbuf(const char *s);
int ft_findreturn(const char *s);
char  *ft_bufbeg(const char *s, int end);
void *ini_mem(int size);

#endif
