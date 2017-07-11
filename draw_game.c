/*
** draw_game.c for draw.c in /home/lyliya/rendu/MUL/wolf3d
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Fri Dec 23 11:09:45 2016 Guillaume
** Last update Sat Jun  3 20:56:31 2017 Guillaume Guerin
*/

#include <math.h>
#include "my.h"

void		set_wall_color(sfColor *wall_color)
{
  wall_color->r = 255;
  wall_color->g = 255;
  wall_color->b = 255;
  wall_color->a = 128;
}

void		draw_wall(int x, t_my_framebuffer *f,
			  float distance, t_player_info *player)
{
  int		y;
  int		top;
  int		base;
  float		hauteur;
  sfColor	wall_color;

  set_wall_color(&wall_color);
  y = 0;
  hauteur = f->height / distance;
  top = ((int) (f->height - hauteur) / 2) + player->vision;
  base = ((int) (f->height + hauteur) / 2) + player->vision;
  if (top <= 0)
    top = 0;
  if (base >= f->height)
    base = f->height;
  if (player->angle > 90)
    distance = distance * cos((player->angle - 90) * M_PI / 180);
  if (player->angle < 90)
    distance = distance * cos((90 - player->angle) * M_PI / 180);
  y = top;
  my_put_pixel(f, x, y++, sfWhite);
  while (y < base - 1)
    my_put_pixel(f, x, y++, wall_color);
  my_put_pixel(f, x, y++, sfWhite);
}

void    crosshair(t_my_framebuffer *f)
{
  int   x;
  int   y;

  x = f->width / 2 - 10;
  y = f->height / 2;
  while (x <= f->width / 2 + 10)
    my_put_pixel(f, x++, y, sfWhite);
  x = f->width / 2;
  y = f->height / 2 - 10;
  while (y <= f->height / 2 + 10)
    my_put_pixel(f, x, y++, sfWhite);
}

void		my_draw_sky_ground(t_my_framebuffer *f, int vision)
{
  int		i;
  int		j;
  sfColor	ground_color;

  ground_color.r = 89;
  ground_color.g = 89;
  ground_color.b = 89;
  ground_color.a = 100;
  i = 0;
  while (i <= f->width)
    {
      j = 0;
      while (j <= f->height)
	{
	  if (j < f->height / 2 + vision)
	    my_put_pixel(f, i, j++, sfBlue);
	  else
	    my_put_pixel(f, i, j++, ground_color);
	}
      i += 1;
    }
}

void		draw(t_my_framebuffer *f, t_graph *g, t_player_info *player, t_map *m)
{
  sfSprite_setTexture(g->sprite, g->texture, sfTrue);
  my_draw_sky_ground(f, player->vision);
  my_find_wall(f, *player, m);
  crosshair(f);
  sfTexture_updateFromPixels(g->texture, f->pixels, f->width, f->height, 0, 0);
  sfRenderWindow_clear(g->window, sfBlack);
  clearpixels(f->width, f->height, f->pixels);
  sfRenderWindow_drawSprite(g->window, g->sprite, NULL);
  sfRenderWindow_display(g->window);
}
