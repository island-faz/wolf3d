/*
** gere_expose.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 15:52:17 2013 bourhime amine
** Last update Thu Dec 19 01:07:16 2013 
*/

#include "../include/wolf3d.h"

int		gere_expose(void *p)
{
  t_graphics	*wlf;

  wlf = (t_graphics*)p;
  mlx_put_image_to_window(wlf->mlx_ptr, wlf->win_ptr, wlf->img_ptr, 0, 0);
  return (0);
}
