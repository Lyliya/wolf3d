/*
** my.h for my.h in /home/lyliya/rendu/MUL/wolf3d/include
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Wed Dec 21 20:03:49 2016 Guillaume
** Last update Thu Jan  5 13:46:00 2017 Guillaume
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics.h>
# include <SFML/System.h>
# include <SFML/Window/Keyboard.h>

typedef struct		s_map
{
  char			*buffer;
  int			**map;
  sfVector2i		mapSize;
}			t_map;

typedef struct		s_my_framebuffer
{
  sfUint8*		pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_size
{
  int			height;
  int			width;
}			t_size;

typedef struct		s_affine
{
  float			x;
  float			y;
  float			a;
  float			b;
}			t_affine;

typedef struct          s_graph
{
  sfRenderWindow*       window;
  sfTexture*            texture;
  sfSprite*             sprite;
  sfColor               color;
}                       t_graph;

typedef	struct		s_player_info
{
  sfVector2f		pos;
  float			angle;
  int			vision;
  float			speed;
}			t_player_info;

typedef	struct		s_sprite
{
  sfTexture*		weapon;
  sfSprite*		sp_weapon;
  sfVector2f		pos_weapon;
}			t_sprite;

sfRenderWindow          *open_window(int, int);
t_my_framebuffer        *my_framebuffer_create(int, int);
void                    my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void                    my_draw_line(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);
void                    my_draw_vertical_line(t_my_framebuffer *, sfVector2i,
					      sfVector2i, sfColor);
void                    my_draw_x(t_my_framebuffer *, sfVector2i, sfVector2i,
				  sfColor);
void                    my_draw_y(t_my_framebuffer *, t_affine *,
				  int, sfColor);
int			**fill_map(t_map *);
char			*create_buffer(char *, char **);
sfVector2f		move_forward(sfVector2f, float, float);
int			**get_map(t_map *);
float			raycast(sfVector2f, float, int **, sfVector2i);
int			get_size(t_map *, char *);
void			draw(t_my_framebuffer *, t_graph *, t_player_info *,
			     t_map *);
void			my_draw_sky_ground(t_my_framebuffer *, int);
void			crosshair(t_my_framebuffer *);
void			draw_wall(int, t_my_framebuffer *, float,
				  t_player_info *);
void			clearpixels(int, int, sfUint8 *);
void			my_find_wall(t_my_framebuffer *,
				     t_player_info, t_map *);
int			spawn(t_map *, sfVector2f *, t_player_info *);
int			map_close_x_y(t_map *);
int			map_close_y_x(t_map *);
void			arrow_keyUp(t_map *, t_player_info *, float,
				    t_my_framebuffer *);
void			arrow_keyDown(t_map *, t_player_info *, float,
				      t_my_framebuffer *);

#endif /* !MY_H_ */
