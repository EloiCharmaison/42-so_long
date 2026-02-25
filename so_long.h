/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:19:24 by echarmai          #+#    #+#             */
/*   Updated: 2026/01/26 12:50:07 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
}	t_game;

int		main(int argc, char **argv);
int		map_checker(char **map);
int		check_rectangle(char **map);
int		check_walls(char **map);
char	**read_map(char *filename);
int		count_line(char *filename);
void	load_images(t_game *game);
void	mlx_init_game(t_game *game);
int		get_map_width(char **map);
int		get_map_height(char **map);
void	mlx_init_game(t_game *game);
void	load_images(t_game *game);
int		close_game(t_game *game);
void	render_map(t_game *game);
void	find_player_and_collectibles(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		check_move(t_game *game, char next);
int		wall_parse(int height, int width, char **map);
void	map_parse(t_game *game, int x, int y);
int		check_chars(char **map);
int		check_min_chars(char **map);
void	count_chars(char **map, int *p, int *e, int *c);
int		flood(char **map);
char	**copy_map(char **map);
int		check_flood(char **map);
void	find_player(char **map, int *x, int *y);
void	flood_fill(char **map, int x, int y);
int		map_name_checker(int argc, char *filename);
void	free_grid(char **grid);
void	destroy_images(t_game *game);

#endif
