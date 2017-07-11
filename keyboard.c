/*
** keyboard.c for  in /home/lyliya/rendu/MUL/wolf3d
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Fri Dec 23 20:08:34 2016 Guillaume
** Last update Wed Jan  4 15:38:14 2017 Guillaume
*/

#include "my.h"

void		arrow_keyUp(t_map *m, t_player_info *player,
		    float speed, t_my_framebuffer *f)
{
  sfVector2f	map;
  int		crosshair;

  crosshair = player->angle - f->width / 4;
  map = move_forward(player->pos, crosshair, -0.5);
  if (m->map[(int) map.x][(int) map.y] == 0)
    player->pos = move_forward(player->pos, crosshair, -speed);
}

void		arrow_keyDown(t_map *m, t_player_info *player,
		      float speed, t_my_framebuffer *f)
{
  sfVector2f	map;
  int		crosshair;

  crosshair = player->angle - f->width / 4;
  map = move_forward(player->pos, crosshair, 0.5);
  if (m->map[(int) map.x][(int) map.y] == 0)
    player->pos = move_forward(player->pos, crosshair, speed);
}
