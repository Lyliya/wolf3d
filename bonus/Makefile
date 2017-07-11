##
## Makefile for Makefile in /home/lyliya/rendu/MUL/wireframe
## 
## Made by Guillaume
## Login   <lyliya@epitech.net>
## 
## Started on  Wed Dec  7 10:27:51 2016 Guillaume
## Last update Wed Jan  4 12:28:17 2017 Guillaume
##

SRC	=	src/move_forward.c		\
		src/raycast.c			\
		wolf.c				\
		draw_game.c			\
		window/main.c			\
		src/my_draw_line.c		\
		window/my_framebuffer_create.c	\
		window/open_window.c		\
		src/my_put_pixel.c		\
		keyboard.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Iinclude

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

NAME	=	wolf3d

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
