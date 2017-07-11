/*
** raycast.c for raycast in /home/lyliya/rendu/MUL/bswolf3d/src
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Tue Dec 20 08:11:07 2016 Guillaume
** Last update Mon Jan  2 16:47:59 2017 Guillaume
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char	*create_buffer(char *buffer, char **argv)
{
  int	i;
  int	fd;
  char	temp[1];

  i = 0;
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
      write(2, "Invalid map\n", 12);
      return (NULL);
    }
  while (read(fd, temp, 1) != 0)
    {
      if (temp[0] != '0' && temp[0] != '1' && temp[0] != '\n')
	return (NULL);
      i += 1;
    }
  close(fd);
  if ((buffer = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  fd = open(argv[1], O_RDONLY);
  read(fd, buffer, i);
  buffer[i] = '\0';
  close(fd);
  return (buffer);
}

int	**fill_map(t_map *m)
{
  int	i;
  int	j;
  int	b;

  i = 0;
  j = 0;
  b = 0;
  while (j < m->mapSize.y)
    {
      i = 0;
      while (i < m->mapSize.x)
	{
	  m->map[i++][j] = m->buffer[b++] - 48;
	}
      b += 1;
      j += 1;
    }
  return (m->map);
}

int	**get_map(t_map *m)
{
  int	i;

  i = 0;
  if ((m->map = malloc(sizeof(int *) * (m->mapSize.x + 1))) == NULL)
    return (NULL);
  while (i < m->mapSize.x)
    {
      if ((m->map[i++] = malloc(sizeof(int) * (m->mapSize.y + 1))) == NULL)
	return (NULL);
    }
  m->map = fill_map(m);
  if ((map_close_x_y(m)) == 84)
    return (NULL);
  if ((map_close_y_x(m)) == 84)
    return (NULL);
  return (m->map);
}

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
  float		khey;
  float		distance;
  sfVector2f	cartesien;
  int		x;
  int		y;

  khey = 0;
  x = pos.x;
  y = pos.y;
  while (map[x][y] == 0 && (x < mapSize.x && x >= 0) &&
	 (y < mapSize.y && y > 0))
    {
      cartesien = move_forward(pos, direction, khey);
      x = (int) cartesien.x;
      y = (int) cartesien.y;
      khey += 0.01;
    }
  distance = sqrtf(pow((cartesien.x - pos.x), 2) +
		   pow((cartesien.y - pos.y), 2));
  return (distance);
}
