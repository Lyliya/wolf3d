
/*
** open_window.c for open_window in /home/lyliya/g_graph
** 
** Made by Guillaume
** Login   <lyliya@epitech.net>
** 
** Started on  Wed Nov  9 11:06:15 2016 Guillaume
** Last update Fri Dec 23 21:47:03 2016 Guillaume
*/

#include <stdlib.h>
#include "my.h"

sfRenderWindow		*open_window(int width, int height)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "Wolf3D", sfResize | sfClose, NULL);
  sfRenderWindow_setFramerateLimit(window, 30);
  if (window == NULL)
    exit(84);
  return (window);
}
