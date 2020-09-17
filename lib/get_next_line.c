/*
** get_next_line.c for gnl in ~/rendu/prog_elem/get_next_line-2017-bourhi_a
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Nov 19 04:44:18 2013 
** Last update Mon Dec 23 02:36:05 2013 
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		my_strlen(char *a)
{
  int		i;

  i = 0;
  while (a && a[i])
    i++;
  return (i);
}

char		*merge_string(char *a, char *b)
{
  int		i;
  int		j;
  int		a_len;
  int		b_len;
  char		*res;

  i = 0;
  j = 0;
  a_len = my_strlen(a);
  b_len = my_strlen(b);
  res = malloc(a_len + b_len + 1);
  while (i < a_len)
    res[i] = a[i++];
  while (j < b_len)
    res[i++] = b[j++];
  res[i] = '\0';
  return (res);
}

char		*my_read(const int fd)
{
  char		*res;
  int		size;

  res = malloc(BUFF_SIZE + 1);
  if ((size = read(fd, res, BUFF_SIZE)) <= 0)
    return (0);
  res[size] = '\0';
  return (res);
}

int		n_exist(char *s)
{
  int		i;

  if (!s)
    return (0);
  i = 0;
  while (s[i])
    {
      if (s[i] == '\n')
	return (i);
      i++;
    }
  return (-1);	
}

char		*get_next_line(const int fd)
{
  char		*tmp;
  char		*line;
  static char	*buf = "";
  int		i;

  while (1)
    {
      if ((tmp = my_read(fd)))
      	buf = merge_string(buf, tmp);
      else if (!buf || my_strlen(buf) == 0)
	return (0);
      if ((i = n_exist(buf)) != -1)
	{
	  buf[i] = '\0';
	  line = merge_string(buf, "");
	  buf = buf + i + 1;
	  return (line);
	}
      else if (!tmp || my_strlen(tmp) == 0)
	{
	  line = buf;
	  buf = 0;
	  return (merge_string(line, ""));
	}
    }
}
