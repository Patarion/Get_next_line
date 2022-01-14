/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:17:33 by jgagnon           #+#    #+#             */
/*   Updated: 2022/01/10 11:17:37 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   BUFFER_SIZE = 42;

char *get_next_line(int fd)
{
  int         r_read;
  char        lecture[BUFFER_SIZE + 1];
  char        *r_ligne;
  static char *buffer;

  if ((r_read = read(fd, lecture, 0)) < 0 || BUFFER_SIZE < 1)
    return(0);
  while ((r_read = read(fd,lecture, BUFFER_SIZE)) > 0)
  {
    buffer = ft_strconcatenate(buffer, lecture);
    if (ft_findreturn(buffer) != 0)
      break;
  }
  r_ligne = ft_bufdup(buffer, ft_findreturn(buffer) + 1);
  if (r_read > -1 && r_ligne != 0)
  {
    buffer = ft_subbuf(buffer, ft_findreturn(buffer) + 1);
    return (r_ligne);
  }
  else
    return (0);
}

int main (void)
{
  int   fd;
  char  *r_txt;
  int    i;

  i = -1;
  fd = open("File.txt", O_RDONLY);
  while (++i < 8)
  {
    r_txt = get_next_line(fd);
    printf("%s", r_txt);
  }
}
