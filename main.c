/*
** main.c for FDF in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Dec  3 01:01:47 2013 bourhime amine
** Last update Fri Jan 17 13:05:53 2014 
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/wolf3d.h"

void		clear_image(int	*img, int end)
{
  int	i;

  i = 0;
  while (i < end)
    img[i++] = 0;
}

int		draw_frame(t_wolf *wolf)
{
  t_distance	distance;
  t_point	p1;
  t_point	p2;
  int		i;
  double	angle_tmp;

  clear_image(wolf->img->data, wolf->img->end);
  angle_tmp = wolf->camera.angle;
  wolf->camera.angle += 30;
  i = -1;
  while (++i < WIDTH)
    {
      distance = get_distance(&wolf->camera, wolf->map);
      p1.x = i;
      p2.x = i;
      distance.dis = ABS(FACE_LENGTH / distance.dis * 150);
      p1.y = HEIGHT / 2 - (int)distance.dis / 2;
      p2.y = (int)distance.dis + p1.y;
      draw_line(p1, p2, wolf->img, distance.color);
      wolf->camera.angle -= (double)60 / (double)WIDTH;
    }
  wolf->camera.angle = angle_tmp;
  mlx_put_image_to_window(wolf->gr->mlx_ptr, wolf->gr->win_ptr, 
			  wolf->gr->img_ptr, 0, 0);
  mlx_do_sync(wolf->gr->mlx_ptr);
}

int		main(int ac, char **av)
{
  int		fd;
  t_wolf	wolf;

  if ((fd = open(MAP_PATH, O_RDONLY)) == -1)
    {
      perror("wolf3d");
      return (1);
    }
  wolf.gr = malloc(sizeof(t_graphics));
  wolf.img = malloc(sizeof(t_image));
  init_graphics(wolf.gr, wolf.img, "wolf3d");
  wolf.map = get_map(fd);
  wolf.camera.x = (int)(1.5 * FACE_LENGTH);
  wolf.camera.y = (int)(3.5 * FACE_LENGTH);
  wolf.camera.angle = 90;
  draw_frame(&wolf);
  mlx_put_image_to_window(wolf.gr->mlx_ptr, wolf.gr->win_ptr, wolf.gr->img_ptr, 0, 0);
  mlx_do_sync(wolf.gr->mlx_ptr);
  mlx_hook(wolf.gr->win_ptr, KeyPress, KeyPressMask, &manage_key, &wolf);
  mlx_do_key_autorepeaton(wolf.gr->mlx_ptr);
  mlx_expose_hook(wolf.gr->win_ptr, gere_expose, wolf.gr);
  mlx_loop(wolf.gr->mlx_ptr);
  return (0);
}
