/*
** wolf3d.h for wolf3d in /home/bourhi_a/rendu/MUL_2013_wolf3d
** 
** Made by amine bourhime
** Login   <bourhi_a@epitech.net>
** 
** Started on  Wed Dec 18 03:46:45 2013 
** Last update Mon Jan 20 01:18:01 2014 
*/

#ifndef		        WOLF3D_H_
# define		WOLF3D_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"

# define EMPTY_MAP		"map is empty !\n"
# define MAP_MISSING		"map is missing !\n"
# define MAP_PATH		"maps/m.w3d"
# define ABS(x)			((((x)) < 0) ? (-(x)) : ((x)))
# define M_PI		        3.14159265358979323846

# define HEIGHT			600
# define WIDTH			600

# define D_CAM_SCR		277
# define EPSY			0.0000001
# define ZERO			0
# define KeyPressMask		(1L<<0)
# define KeyPress		2
# define UP_KEY			65362
# define RIGHT_KEY		65363
# define DOWN_KEY		65364
# define LEFT_KEY		65361
# define EXIT_KEY		65307
# define GREEN_COLOR		0x00FF00
# define BLUE_COLOR		0x0000FF
# define FACE_LENGTH		64

typedef struct	s_array
{
  int		**array;
  int		i;
  int		j;
}		t_array;

typedef struct	s_distance
{
  double	dis;
  int		color;
}		t_distance;

typedef struct	s_point
{
  int		x;
  int		y;
  int		z;
}		t_point;

typedef struct	s_dpoint
{
  double       	x;
  double	y;
  double	z;
}		t_dpoint;

typedef struct	s_image
{
  int		bpp;
  int		sizeline;
  int		*data;
  int		endian;
  int		end;
}		t_image;

typedef struct  s_my_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
}		t_graphics;

typedef struct s_camera
{
  int		x;
  int		y;
  double	angle;
}		t_camera;

typedef struct	s_wolf
{
  t_graphics	*gr;
  t_array	map;
  t_image	*img;
  t_camera	camera;
}		t_wolf;

void		put_pixel_in_image(t_point p, t_image *img, int color);
void		draw_line(t_point p1, t_point p2, t_image *img, int color);
int		gere_expose(void *p);
int		init_graphics(t_graphics *gr, t_image *img, char *window_title);
char		*get_next_line(const int fd);
t_array		my_realloc(t_array *arr, char *line, int n);
char		**my_str_to_wordtab(char *str);
void		my_putchar(char c);
t_array		get_map(int fd);
t_distance	get_distance(t_camera *camera, t_array map);
int		manage_key(int key, void *p);
double		deg_to_rad(double angle);

#endif		/* WOLF3D_H_ */
