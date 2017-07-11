/*
** my_put_pixel.c for my_put_pixel in /home/lyliya/rendu/G_Graphical_prog
** 
** Made by Guillaume
** Login   <lyliya@epitech.net>
** 
** Started on  Mon Nov 14 07:45:15 2016 Guillaume
** Last update Wed Jan  4 15:38:59 2017 Guillaume
*/

#include "my.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (((framebuffer->width * y + x) * 4) > framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
