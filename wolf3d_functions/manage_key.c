/*
** manage_key.c for wolf3d in /home/bourhi_a/rendu/MUL_2013_wolf3d/wolf3d_functions
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri Jan 10 14:27:48 2014 
** Last update Mon Jan 13 00:38:32 2014 
*/

#include <math.h>
#include "../include/wolf3d.h"

void	check_for_exit(int key)
{
  if (key == EXIT_KEY)
    exit(0);
}

void		check_right_left(int key, t_wolf *wolf)
{
  if (key == RIGHT_KEY)
    {
      if (wolf->camera.angle == 0)
	wolf->camera.angle = 359;
      else
	wolf->camera.angle -= 3;
      draw_frame(wolf);
    }
  else if (key == LEFT_KEY)
    {
      if (wolf->camera.angle == 359)
	wolf->camera.angle = 0;
      else
	wolf->camera.angle += 3;
      draw_frame(wolf);
    }  
}

void		check_up(int key, t_wolf *wolf)
{
  float		t1;
  float		t2;

  if (key == UP_KEY)
    {
      t1 = wolf->camera.x;
      t2 = wolf->camera.y; 
      wolf->camera.x += 10 * cos(deg_to_rad(wolf->camera.angle));
      wolf->camera.y -= 10 * sin(deg_to_rad(wolf->camera.angle));
      if (wolf->map.array[(int)(wolf->camera.y/ FACE_LENGTH
				)][(int)(wolf->camera.x /FACE_LENGTH)])
	{
	  wolf->camera.x = t1;
	  wolf->camera.y = t2;
	}
      draw_frame(wolf);
    }
}

int		manage_key(int key, void *p)
{
  t_wolf	*wolf;
  float		t1;
  float		t2;

  check_for_exit(key);
  wolf = (t_wolf*)p;
  check_up(key, wolf);
  if (key == DOWN_KEY)
    {
      t1 = wolf->camera.x;
      t2 = wolf->camera.y; 
      wolf->camera.y += 10 * sin(deg_to_rad(wolf->camera.angle));
      wolf->camera.x -= 10 * cos(deg_to_rad(wolf->camera.angle));
      if (wolf->map.array[(int)(wolf->camera.y/ FACE_LENGTH
				)][(int)(wolf->camera.x /FACE_LENGTH)])
	{
	  wolf->camera.x = t1;
	  wolf->camera.y = t2;
	}
      draw_frame(wolf);
    }
  check_right_left(key, wolf);
}
