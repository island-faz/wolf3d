/*
** init_graphics.c for wolf3d in /home/bourhi_a/rendu/MUL_2013_wolf3d
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Dec 19 03:41:26 2013 
** Last update Fri Jan 10 17:02:00 2014 
*/

#include <stdlib.h>
#include "../include/wolf3d.h"

int		init_graphics(t_graphics *gr, t_image *img, char *window_title)
{
  if (!(gr->mlx_ptr = mlx_init()))
    return (1);
  if (!(gr->img_ptr = mlx_new_image(gr->mlx_ptr, WIDTH, HEIGHT)))
    return (1);
  if (!(gr->win_ptr = mlx_new_window(gr->mlx_ptr, WIDTH, HEIGHT, window_title)))
    return (1);
  img->data = (int *)mlx_get_data_addr(gr->img_ptr, &img->bpp,
					    &img->sizeline,
					    &img->endian);
  img->end = (img->sizeline * HEIGHT / 4) - 1;
  mlx_put_image_to_window(gr->mlx_ptr, gr->win_ptr, gr->img_ptr, 0, 0);
}
