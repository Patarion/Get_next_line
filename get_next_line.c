#include "get_next_line_utils.c"
#include "get_next_line.h"

 int BUFFER_SIZE = 10;

char *get_next_line(int fd)
{
  int         r_read;
  char        *lecture;
  char        *r_ligne;
  static char *buffer;

  r_read = 0;
  while (r_read > -1)
  {
    lecture = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
    if (read(fd, lecture, 0) == -1)
      return (0);
    r_read = read(fd, lecture, BUFFER_SIZE);
    buffer = ft_strconcatenate(buffer, lecture);
    free(lecture);
    if (ft_findreturn(buffer) != 0)
      break;
  }
  r_ligne = ft_bufdup(buffer, ft_findreturn(buffer) + 1);
  if (r_read > 0 && r_ligne != 0)
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
  int     i;

  i = -1;
  fd = open("File.txt", O_RDONLY);
  while (++i < 5)
  {
    r_txt = get_next_line(fd);
    printf("%s", r_txt);
  }
}
