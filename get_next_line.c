#include "get_next_line_utils.c"

// #define BUFFER_SIZE 10

char *get_next_line(int fd)
{
  int         r_read;
  char        *lecture;
  char        *r_ligne;
  static char *buffer;

  r_read = 1;
  while (r_read > 0)
  {
    lecture = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
    r_read = read(fd, lecture, 0);
    if (r_read == -1)
      return (0);
    r_read = read(fd, lecture, BUFFER_SIZE);
    buffer = ft_strconcatenate(buffer, lecture);
    free(lecture);
    if (ft_findreturn(buffer) != 0)
      break;
  }
  r_ligne = ft_strdup(buffer, ft_findreturn(buffer) + 1);
  buffer = ft_substr(buffer, ft_findreturn(buffer) + 1);
  return (r_ligne);
}
/*
int main (void)
{
  int   fd;
  char  *r_txt;
  int     i;

  i = -1;
  fd = open("File.txt", O_RDONLY);
  while (++i < 4)
  {
    r_txt = get_next_line(fd);
    printf("%s", r_txt);
  }
}
*/
