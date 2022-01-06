#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char  *ft_bufdup(const char *s, int end)
{
  int j;
  char *ptr;
  if (s[end - 1] == '\\' && s[end] == '0')
    return (0);
  j = 0;
  ptr = (char *)malloc(sizeof(*ptr) * (end + 1));
  if (!ptr)
    return(0);
  while (j < end)
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
    return(ft_bufdup(s2, ft_strlen(s2)));
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
  return (ptr);
}

int ft_findreturn(char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0')
    {
      if ((s[i] == '\\' && (s[i + 1] == 'n' || s[i + 1] == '0')) || s[i] == '\n')
        return (i);
      i++;
    }
  return (0);
}
