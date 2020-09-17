/*
** my_getnbr.c for FDF in /home/bourhi_a/rendu/MUL_2013_fdf/lib
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Dec  4 02:17:23 2013 bourhime amine
** Last update Wed Dec  4 02:18:00 2013 bourhime amine
*/

int	my_getnbr(char *str)
{
  int	 nb;
  int	 isneg;

  nb = 0;
  isneg = 1;
  while (*str == '+' || *str == '-')
     {
       if (*str == '-')
	 {
	   isneg *= -1;
	 }
       str = str + 1;
     }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      nb = nb * 10;
      nb = nb + *str - 48;
      str = str + 1;
    }
  return (nb * isneg);
}
