/*
** my_framebuffer_create.c for my_framebuffer_create in /home/lyliya/rendu/G_Graphical_prog
** 
** Made by Guillaume
** Login   <lyliya@epitech.net>
** 
** Started on  Mon Nov 14 07:50:48 2016 Guillaume
** Last update Wed Jan  4 15:30:01 2017 Guillaume
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*framebuffer;

  i = 0;
  if ((framebuffer = malloc(sizeof(*framebuffer))) == NULL)
    return (NULL);
  framebuffer->width = width;
  framebuffer->height = height;
  if ((framebuffer->pixels = malloc(width * height * 4 * sizeof(*framebuffer)))
      == NULL)
    return (NULL);
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i += 1;
    }
  return (framebuffer);
}
