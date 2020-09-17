/*
** get_distance.c for wolf3d in /home/bourhi_a/rendu/MUL_2013_wolf3d
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Dec 23 04:40:12 2013 
** Last update Fri Jan 10 21:58:36 2014 
*/

#include <stdio.h>
#include <math.h>
#include "../include/wolf3d.h"

double		get_horizontal_distance(t_camera *cam, t_array map, t_point dir_vec)
{
  t_dpoint	inter_a;
  t_dpoint	a;
  int		tmp;

  inter_a.x = ABS(1 / tan(cam->angle)) * dir_vec.x;
  inter_a.y = dir_vec.y;

  a.y = (int)cam->y + dir_vec.y;
  a.x = cam->x + EPSY + (cam->y - a.y) / tan(cam->angle);

  while (a.x >= 0 && a.y >= 0 && a.x < map.j && a.y < map.i)
    {
      if ((int)(a.y - 1) >= 0 && (int)a.x >= 0 && map.array[(int)(a.y - 1)][(int)a.x])
  	{
  	  /* printf("sh(%d,%d) ", (int)a.x, (int)a.y); */
  	  tmp = dir_vec.y + (dir_vec.y < 0) ? 1 : -1;
  	  return (ABS(ABS(cam->y - a.y * tmp ) / sin(cam->angle)) + tmp);
  	}
      if ((int)a.y >= 0 && (int)a.x >= 0 && map.array[(int)a.y][(int)a.x])
  	{
  	  /* printf("sh(%d,%d) ", (int)a.x, (int)a.y); */
  	  tmp = dir_vec.y + (dir_vec.y < 0) ? 1 : -1;
  	  return (ABS(ABS(cam->y - a.y * tmp ) / sin(cam->angle)) + tmp);
  	}
      a.x += inter_a.x;
      a.y += inter_a.y;
    }
  return (-1);
}

double		get_vertical_distance(t_camera *cam, t_array map, t_point dir_vec)
{
  t_dpoint	inter_b;
  t_dpoint	b;
  int		tmp;

  inter_b.x = dir_vec.x;
  inter_b.y = ABS(tan(cam->angle)) * dir_vec.y;

  b.x = (int)cam->x + dir_vec.x;
  b.y = (cam->y + (cam->x - b.x) * tan(cam->angle));

  while (b.x >= 0 && b.y >= 0 && b.x < map.j && b.y < map.i)
    {
      if ((int)b.y >= 0 && (int)(b.x - 1) >= 0 && map.array[(int)b.y][(int)(b.x - 1)])
  	{
  	  /* printf("sv(%d,%d) ", (int)b.x, (int)b.y); */
  	  tmp = dir_vec.x + (dir_vec.x < 0) ? 1 : -1;
  	  return (ABS(ABS(cam->x - b.x * tmp) / cos(cam->angle)) + tmp);
  	}
      if ((int)b.y >= 0 && (int)b.x >= 0 && map.array[(int)b.y][(int)b.x])
  	{
  	  /* printf("sv(%d,%d) ", (int)b.x, (int)b.y); */
  	  tmp = dir_vec.x + (dir_vec.x < 0) ? 1 : -1;
  	  return (ABS(ABS(cam->x - b.x * tmp) / cos(cam->angle)) + tmp);
  	}
      b.x += inter_b.x;
      b.y += inter_b.y;
    }
  return (-1);
}

double		get_distance(t_camera *camera, t_array map)
{
  t_dpoint	tmp;
  t_point	dir_vec;

  dir_vec.y = (camera->angle > M_PI) ? 1 : -1;
  dir_vec.x = (camera->angle >= M_PI / 2) ? -1 : 1;

  tmp.x = get_vertical_distance(camera, map, dir_vec);
  tmp.y = get_horizontal_distance(camera, map, dir_vec);

  /* printf("vd:(%d,%d) angle:%d v:%f h:%f ", */
  /* 	 dir_vec.x, */
  /* 	 dir_vec.y, */
  /* 	 /\* camera->angle, *\/ */
  /* 	 (int)(180 * camera->angle / M_PI), */
  /* 	 tmp.x, tmp.y); */
  if (tmp.x == -1 && tmp.y == -1)
    return (0.);
  if ((int)tmp.x == 0)
    return (tmp.y);
  if((int)tmp.y == 0)
    return (tmp.x);
  if (tmp.x == -1)
    return (tmp.y);
  if (tmp.y == -1)
    return(tmp.x);
  if (tmp.x > tmp.y)
    return(tmp.y);
  return (tmp.x);
}
