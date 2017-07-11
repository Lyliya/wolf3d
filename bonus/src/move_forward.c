/*
** move_forward.c for move_forward.C in /home/lyliya/rendu/MUL/bswolf3d
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Mon Dec 19 15:49:20 2016 Guillaume
** Last update Thu Dec 22 19:12:23 2016 Guillaume
*/

#include <SFML/System/Vector2.h>
#include <math.h>

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  pos.x = cos((direction * (M_PI / 180))) * distance + pos.x;
  pos.y = sin((direction * (M_PI / 180))) * distance + pos.y;
  return (pos);
}
