/*
** my_realloc.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat Dec  7 19:11:39 2013 bourhime amine
** Last update Mon Dec 23 02:13:21 2013 
*/

#include "../include/wolf3d.h"

t_array		my_realloc(t_array *arr, char *line, int n)
{
  t_array	ret;
  char		**wt;
  int		*tmp;
  int		i;
  int		j;

  i = 0;
  ret.array = malloc((n + 1) * sizeof(int *));
  ret.i = n + 1;
  while (i < n)
    ret.array[i] = arr->array[i++];
  wt = my_str_to_wordtab(line);
  i = 0;
  while (wt[i++]);
  if (arr->j > i - 1 || arr->j == -1)
    arr->j = i - 1;
  ret.j = arr->j;
  tmp = malloc(sizeof(int) * i);
  i = 0;
  while (i < ret.j)
    tmp[i] = my_getnbr(wt[i++]);
  ret.array[n] = tmp;
  return (ret);
}
