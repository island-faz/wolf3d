/*
** my_str_to_wordtab.c for my_str_to_wordtab in ~/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Oct 10 10:41:01 2013 bourhime amine
** Last update Mon Dec 23 02:22:46 2013 
*/

#include <stdlib.h>
#include "../include/wolf3d.h"

int	is_alphanum(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  else if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	nbr_sep(char *str)
{
  int	i;
  int	len;
  int	nb_sep;

  nb_sep = 0;
  len = my_strlen(str);
  i = -1;
  while (++i < len)
    if (!is_alphanum(str[i]) && is_alphanum(str[i + 1]))
      nb_sep++;
  return (is_alphanum(str[0])) ? (nb_sep + 1) : (nb_sep);
}

char	*get_next_word(char *str)
{
  if (!str || !(*str))
    return (0);
  return (is_alphanum(*str)) ? str : get_next_word(++str);
}

char		**my_str_to_wordtab(char *str)
{
  int		i;
  char		*temp;
  char		**res;
  int		res_compteur;
  int		nbsep;

  if (!str)
    return (0);
  nbsep = nbr_sep(str);
  res = malloc(sizeof(char *) * (nbsep + 1 + 50));
  res_compteur = 0;
  while (str && *str)
    if ((str = get_next_word(str)))
      {
	i = 0;
	while (is_alphanum(str[i]) && ++i);
	temp = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (is_alphanum(*str) && (temp[i++] = *str++))
	  temp[i] = '\0';
	res[res_compteur++] = temp;
      }
  res[res_compteur] = 0;
  return (res);
}
