##
## Makefile for Makefile in /home/bourhi_a/rendu/Piscine-C-lib/my
## 
## Made by bourhime amine
## Login   <bourhi_a@epitech.net>
## 
## Started on  Mon Oct 21 11:02:20 2013 bourhime amine
## Last update Fri Jan 17 13:40:08 2014 
##

SRC		= 	main.c \
			lib/get_map.c \
			lib/my_putchar.c \
			lib/my_realloc.c \
			lib/my_getnbr.c \
			lib/my_putstr.c	\
			lib/get_next_line.c \
			lib/my_str_to_wordtab.c \
			wolf3d_functions/draw_line.c \
			wolf3d_functions/get_distance.c \
			wolf3d_functions/gere_expose.c \
			wolf3d_functions/init_graphics.c \
			wolf3d_functions/put_pixel_in_image.c \
			wolf3d_functions/manage_key.c

OBJ		=	$(SRC:.c=.o)

MINILIBX	=	minilibx

NAME		=	wolf3d

CC		=	cc -g

CFLAGS		=	-Werror -ansi -pedantic -Wextra

HOST		=	$(HOSTTYPE)

RM		=	rm -f

LDFLAGS		=	-lm -L/usr/lib64 -L./minilibx -lmlx -L/usr/lib64/X11 -lXext -lX11

BCP		=	*~

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MINILIBX)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C $(MINILIBX)
	$(RM) $(OBJ) $(BCP) wolf3d_functions/$(BCP) lib/$(BCP) include/$(BCP)

fclean:	clean
	make fclean -C $(MINILIBX)
	$(RM) $(NAME)

re:	fclean all
