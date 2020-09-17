/*
** draw_line.c for FDF in /home/bourhi_a/rendu/MUL_2013_fdf/fdf_functions
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Dec  3 13:26:24 2013 bourhime amine
** Last update Mon Dec 23 06:55:35 2013 
*/

#include "../include/wolf3d.h"

void		drawYLine(t_point p1, t_point p2, t_image *img, int color)
{
  int		y;
  int		tmp;
  t_point	p;

  y = p1.y;
  while (y <= p2.y)
    {
      if (p2.y - p1.y)
	{
	  tmp = p1.x + ((p2.x - p1.x) * (y - p1.y)) / (p2.y - p1.y);
	  p.x = tmp;
	  p.y = y;
	  put_pixel_in_image(p, img, color); 
	}
      y++;
    }
}

void		drawXLine(t_point p1, t_point p2, t_image *img, int color)
{
  int		x;
  int		tmp;
  t_point	p;

  x = p1.x;
  while (x <= p2.x)
    {
      if (p2.x - p1.x != 0)
	{
	  tmp =  p1.y + ((p2.y - p1.y) * (x - p1.x)) / (p2.x - p1.x);
	  p.x = x;
	  p.y = tmp;
	  put_pixel_in_image(p, img, color); 
	}
      x++;
    }
}

void	draw_line(t_point p1, t_point p2, t_image *img, int color)
{
  if (p1.x == p2.x && p1.y == p2.y)
      put_pixel_in_image(p1, img, color);
  else if (ABS(p1.x - p2.x) > ABS(p1.y - p2.y))
    {
      if (p2.x > p1.x)
	drawXLine(p1, p2, img, color);
      else
	drawXLine(p2, p1, img, color);
    }
  else
    {
      if (p2.y > p1.y)
	drawYLine(p1, p2, img, color);
      else
	drawYLine(p2, p1, img, color);
    }
}
