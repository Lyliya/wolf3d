/*
** main.c for main in /home/Lyliya/wireframe/G_Graphical_prog
**
** Made by Guillaume Guerin
** Login   <Lyliya@epitech.net>
**
** Started on  Mon Nov 14 16:47:17 2016 Guillaume Guerin
** Last update Thu Jan  5 11:55:39 2017 Guillaume
*/

#include <SFML/Window/Joystick.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

void	clearpixels(int width, int height, sfUint8* pixels)
{
  int	i;

  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i += 1;
    }
}

void	my_find_wall(t_my_framebuffer *f, t_player_info player, t_map *m)
{
  int	x;
  float	distance;

  x = 0;
  while (x < f->width)
    {
      distance = raycast(player.pos, player.angle, m->map, m->mapSize);
      draw_wall(x, f, distance, &player);
      x += 1;
      player.angle += 0.060;
    }
}

int		play_game(t_graph *graph,
			  t_my_framebuffer *framebuffer, t_map *m)
{
  t_player_info	player;

  if ((spawn(m, &player.pos, &player)) == 84)
    return (84);
  while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
    {
      if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
	arrow_keyUp(m, &player, player.speed, framebuffer);
      if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
	arrow_keyDown(m, &player, player.speed, framebuffer);
      if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
	player.angle -= 2;
      if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
	  player.angle += 2;
      if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && player.vision <= 240)
	player.vision += 10;
      if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue && player.vision >= -240)
	player.vision -= 10;
      if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
	player.speed = 0.10;
      else
	player.speed = 0.05;
      draw(framebuffer, graph, &player, m);
    }
  return (0);
}

int			main(int argc, char **argv)
{
  t_graph		graph;
  t_my_framebuffer	*framebuffer;
  t_size		size;
  t_map			m;

  if (argc != 2)
    return (84);
  size.width = 640;
  size.height = 480;
  if ((framebuffer = my_framebuffer_create(size.width, size.height)) == NULL)
    return (84);
  graph.window = open_window(framebuffer->width, framebuffer->height);
  graph.sprite = sfSprite_create();
  graph.texture = sfTexture_create(framebuffer->width, framebuffer->height);
  if ((m.buffer = malloc(sizeof(void))) == NULL)
    return (84);
  if ((m.buffer = create_buffer(m.buffer, argv)) == NULL)
    return (84);
  if ((get_size(&m, m.buffer)) == 84)
    return (84);
  if ((get_map(&m)) == NULL)
    return (84);
  play_game(&graph, framebuffer, &m);
  sfRenderWindow_destroy(graph.window);
  return (0);
}
