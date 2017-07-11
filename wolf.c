/*
** wolf.c for wolf.c in /home/lyliya/rendu/MUL/wolf3d
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Wed Dec 21 20:01:47 2016 Guillaume
** Last update Mon Jan  2 16:58:08 2017 Guillaume
*/

#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include <unistd.h>
#include "my.h"

int		map_close_y_x(t_map *m)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y < m->mapSize.y - 1)
    {
      if (m->map[x][y] != 1)
	return (84);
      y += 1;
    }
  while (x < m->mapSize.x)
    {
      if (m->map[x][y] != 1)
	return (84);
      x += 1;
    }
  return (0);
}

int		map_close_x_y(t_map *m)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (x < m->mapSize.x - 1)
    {
      if (m->map[x][y] != 1)
	return (84);
      x += 1;
    }
  while (y < m->mapSize.y)
    {
      if (m->map[x][y] != 1)
	return (84);
      y += 1;
    }
  return (0);
}

int		spawn(t_map *m, sfVector2f *pos, t_player_info *player)
{
  int		x;
  int		y;

  x = 0;
  player->angle = 60;
  player->vision = 0;
  player->speed = 0.05;
  while (x < m->mapSize.x)
    {
      y = 0;
      while (y < m->mapSize.y)
	{
	  if (m->map[x][y] == 0)
	    {
	      pos->x = x + 0.5;
	      pos->y = y + 0.5;
	      return (0);
	    }
	  y += 1;
	}
      x += 1;
    }
  return (84);
}

int	get_size(t_map *m, char *buffer)
{
  int	i;
  int	columns;
  int	line;
  int	bool;

  i = 0;
  line = 0;
  bool = 0;
  m->mapSize.x = 0;
  m->mapSize.y = 0;
  while (buffer[i] != '\0')
    {
      columns = 0;
      while (buffer[i] != '\n' && buffer[i++] != '\0')
	columns += 1;
      if (bool == 0)
	m->mapSize.x = columns;
      if (bool == 1 && columns != m->mapSize.x)
	return (84);
      i += 1;
      line += 1;
      bool = 1;
    }
  m->mapSize.y = line;
  return (0);
}
