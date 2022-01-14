/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:18:13 by jgagnon           #+#    #+#             */
/*   Updated: 2022/01/10 11:18:17 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *ft_bufdup(const char *s, int end)
{
  int j;
  char *ptr;

  j = 0;
  ptr = (char *)malloc(sizeof(*ptr) * (end + 1));
  if (!ptr)
    return(0);
  while (j < end && s[j] != '\0')
  {
    ptr[j] = s[j];
    j++;
  }
  ptr[j] = '\0';
  return (ptr);
}

char  *ft_bufbeg(const char *s, int end)
{
  int j;
  char *ptr;

  j = 0;
  ptr = (char *)malloc(sizeof(*ptr) * (end + 1));
  if (!ptr)
    return(0);
  while (j < end && s[j] != '\0')
  {
    ptr[j] = s[j];
    j++;
  }
  ptr[j] = '\0';
  return (ptr);
}

int ft_strlen(const char * str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*ft_strconcatenate(const char *s1, const char *s2)
{
	int		i;
  int   j;
	char	*ptr;

  i = 0;
  j = 0;
  if (!s2)
    return (0);
  else if (!s1)
    return(ft_bufbeg(s2, ft_strlen(s2)));
  while (s1[i] != '\0')
    i++;
  while (s2[j] != '\0')
    j++;
  ptr = (char *)malloc(sizeof(char *) * (i + j + 1));
  j = -1;
  i = -1;
  while (s1[++i] != '\0')
    ptr[i] = s1[i];
  while (s2[++j] != '\0')
    ptr[i + j] = s2[j];
  ptr[i + j] = '\0';
  free((char*)s1);
  return (ptr);
}

char	*ft_subbuf(const char *s, int start)
{
  char  *ptr;
  int   i;
  int   j;

  i = start;
  j = ft_strlen(s) - i;
  ptr = (char *)malloc(sizeof(*ptr) * (j + 1));
  if (!ptr)
    return (0);
  j = 0;
  while (s[i + j] != '\0')
  {
    ptr[j] = s[i + j];
    j++;
  }
  ptr[j] = '\0';
  free((char*)s);
  return (ptr);
}

int ft_findreturn(char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '\n' || s[i] == '\0' || (s[i] == '\\' && s[i + 1] == '0'))
        return (i);
      i++;
    }
  return (0);
}
