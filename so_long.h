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

#include "../minilibx-linux/mlx.h"
# include <mlx.h>
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
}	t_game;

int	main(int argc, char **argv)
int	map_checker(char **map)
int	check_rectangle(char **map)
int	check_walls(char **map)
char	**read_map(char *filename)
int	count_line(char *filename)
static char	*read_line(int fd)

#endif;
