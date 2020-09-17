/*
** get_distance.c for wolf3d in /home/bourhi_a/rendu/MUL_2013_wolf3d
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Mon Dec 23 04:40:12 2013 
** Last update Mon Jan 13 00:26:38 2014 
*/

#include <stdio.h>
#include <math.h>
#include "../include/wolf3d.h"

double		deg_to_rad(double angle)
{
  return (M_PI * (angle) / 180);
}

double		get_horizontal_distance(t_camera *cam, t_array map)
{
  t_point	a;
  double	angle;
  int		tmp;
  t_point	inter_a;

  tmp = FACE_LENGTH;
  angle = deg_to_rad(cam->angle);
  inter_a.x = ABS((int)(FACE_LENGTH / tan(angle)));
  inter_a.y = FACE_LENGTH;
  if (cam->angle >= 0 && cam->angle <= 180)
    {
      tmp = -1;
      inter_a.y = -FACE_LENGTH;
    }
  a.y = (cam->y / FACE_LENGTH) * FACE_LENGTH + tmp;
  a.x = (cam->x + (cam->y - a.y) / tan(angle));
  while ((int)(a.x / FACE_LENGTH) >= 0 && (int)(a.x / FACE_LENGTH) < map.j &&
	 (int)(a.y / FACE_LENGTH) >= 0 && (int)(a.y / FACE_LENGTH) < map.i)
    {
      if (map.array[(int)(a.y / FACE_LENGTH)][(int)(a.x / FACE_LENGTH)])
	return (ABS((cam->y - a.y)) / sin(angle));
      a.x += inter_a.x;
      a.y += inter_a.y;
    }
  return (100000);
}

double		get_vertical_distance(t_camera *cam, t_array map)
{
  t_point	b;
  double	angle;
  int		tmp;
  t_point	inter_b;

  tmp = FACE_LENGTH;
  angle = deg_to_rad(cam->angle);
  inter_b.x = FACE_LENGTH;
  inter_b.y = -ABS((int)(FACE_LENGTH * tan(angle)));
  if (cam->angle >= 90 && cam->angle <= 270 && (tmp = -1))
    {
      inter_b.x = -FACE_LENGTH;
      inter_b.y *= -1;
    }
  b.x = (int)(cam->x / FACE_LENGTH) * FACE_LENGTH + tmp;
  b.y = (cam->y + (cam->x - b.x) * tan(angle));
  while ((int)(b.x / FACE_LENGTH) >= 0 && (int)(b.x / FACE_LENGTH) < map.j &&
  	 (int)(b.y / FACE_LENGTH) >= 0 && (int)(b.y / FACE_LENGTH) < map.i)
    {
      if (map.array[(int)(b.y / FACE_LENGTH)][(int)(b.x / FACE_LENGTH)])
	return (ABS((cam->x - b.x)) / cos(angle));
      b.x += inter_b.x;
      b.y += inter_b.y;
    }
  return (100000);
}

t_distance	get_distance(t_camera *camera, t_array map)
{
  t_distance	distance;
  t_dpoint	tmp;

  if (camera->angle >= 360)
    camera->angle -= 360;
  else if (camera->angle <= 0)
    camera->angle += 360;
  tmp.x = ABS(get_vertical_distance(camera, map));
  tmp.y = ABS(get_horizontal_distance(camera, map));
  if (tmp.x < tmp.y)
    {
      distance.dis = tmp.x;
      distance.color = GREEN_COLOR;
    }
  else
    {
      distance.dis = tmp.y;
      distance.color = BLUE_COLOR;
    }
  if (distance.dis < 0)
    distance.dis = 0;
  return (distance);
}
