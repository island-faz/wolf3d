/*
** put_pixel_in_image.c for FDF in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Dec  4 16:08:36 2013 bourhime amine
** Last update Fri Jan 17 13:53:03 2014 
*/

#include "../include/wolf3d.h"

void		put_pixel_in_image(t_point p, t_image *img, int color)
{
  int		tmp;

  tmp = p.x + ((img->sizeline / (img->bpp / 8)) * p.y);
  if (tmp <= img->end && tmp > 0)
    img->data[tmp] = color;
}
