/*
** my_draw_line.c for my_draw_line in /home/lyliya/rendu/G_Graphical_prog
** 
** Made by Guillaume
** Login   <lyliya@epitech.net>
** 
** Started on  Mon Nov 14 07:57:05 2016 Guillaume
** Last update Wed Jan  4 15:38:49 2017 Guillaume
*/

#include "my.h"

void		my_draw_x(t_my_framebuffer *frame,
			  sfVector2i from, sfVector2i to, sfColor color)
{
  t_affine	affine;

  affine.x = to.x - from.x;
  affine.y = to.y - from.y;
  affine.a = affine.y / affine.x;
  affine.b = to.y - affine.a * to.x;
  while (from.x < to.x)
    {
      affine.y = affine.a * from.x + affine.b;
      my_put_pixel(frame, from.x, affine.y, color);
      my_draw_y(frame, &affine, from.x, color);
      from.x += 1;
    }
}

void			my_draw_y(t_my_framebuffer *frame,
				  t_affine *affine, int x, sfColor color)
{
  float			z;
  float			y;

  z = affine->a * (x + 1) + affine->b;
  y = affine->y;
  while (y <= z)
    {
      my_put_pixel(frame, x, y, color);
      y += 1;
    }
}

void	my_draw_vertical_line(t_my_framebuffer* frame, sfVector2i from,
			      sfVector2i to, sfColor color)
{
  while (from.y < to.y)
    {
      my_put_pixel(frame, from.x, from.y, color);
      from.y += 1;
    }
}

void	my_draw_line(t_my_framebuffer *framebuffer,
		     sfVector2i from, sfVector2i to, sfColor color)
{
  if (from.x == to.x && from.y > to.y)
    my_draw_vertical_line(framebuffer, to, from, color);
  else if (from.x == to.x && to.y > from.y)
    my_draw_vertical_line(framebuffer, from, to, color);
  else if (from.x + from.y > to.x + to.y)
    my_draw_x(framebuffer, to, from, color);
  else if (from.x + from.y < to.x + to.y)
    my_draw_x(framebuffer, from, to, color);
}
