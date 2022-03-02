/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:17:33 by jgagnon           #+#    #+#             */
/*   Updated: 2022/03/02 15:31:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   BUFFER_SIZE = 100000;

char *get_next_line(int fd)
{
  int         r_read;
  char        *lecture;
  char        *r_ligne;
  static char *buffer;

  r_read = 1;
  lecture = malloc(sizeof(char*) * (BUFFER_SIZE + 1));
  if (!lecture)
  {
    free(lecture);
    return (0);
  }
  if (fd < 0 || read(fd, lecture, 0) < 0 || BUFFER_SIZE < 1)
    return (0);
  while (r_read > 0 && ft_findreturn(buffer) == 0)
  {
    r_read = read(fd,lecture, BUFFER_SIZE);
    lecture[r_read] = '\0';
    buffer = ft_strconcatenate(buffer, lecture);
  }
  	if (ft_findreturn(buffer) > 0)
  		r_ligne = ft_bufdup(buffer, ft_findreturn(buffer) + 1);
	else
	{
		r_ligne = ft_bufdup(buffer, ft_strlen(buffer));
		free(buffer);
		buffer = NULL;
		return(r_ligne);
	}
  if (r_ligne != 0)
  {
    buffer = ft_subbuf(buffer, ft_findreturn(buffer) + 1);
    return (r_ligne);
  }
  return (0);
}

int main (void)
{
  int   fd;
  char  *r_txt;
  int    i;

  i = -1;
  fd = open("File.txt", O_RDONLY);
  while (++i < 2)
  {
    r_txt = get_next_line(fd);
    printf("%s", r_txt);
  }
}
