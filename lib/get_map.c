/*
** get_map.c for wolf3d in /home/bourhi_a/rendu/MUL_2013_wolf3d
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Dec 23 02:29:25 2013 
** Last update Mon Dec 23 02:29:48 2013 
*/

#include "../include/wolf3d.h"

t_array			get_map(int fd)
{
  int			i;
  int			j;
  t_array		map;
  char			*s;

  i = 0;
  map.j = -1;
  map.i = 0;
  while ((s = get_next_line(fd)))
    map = my_realloc(&map, s, i++);
  if (map.i == 0)
    {
      my_putstr(EMPTY_MAP);
      exit (1);
    }
  i = 0;
  while (i < map.i)
    {
      j = 0;
      while (j < map.j)
	j++;
      i++;
    }
  return (map);
}
