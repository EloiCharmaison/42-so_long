/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:43:16 by marvin            #+#    #+#             */
/*   Updated: 2026/01/27 10:43:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void load_images(t_game *game)
{
	int	w;
	int	h;

	w = TILE;
	h = TILE;
	game->img_wall = mlx_xpm_file_to_image(
		game->mlx, "assets/black_square.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(
		game->mlx, "assets/blue_square.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(
		game->mlx, "assets/green_square.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(
		game->mlx, "assets/yellow_square.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(
		game->mlx, "assets/red_square.xpm", &w, &h);

	if (!game->img_wall || !game->img_floor || !game->img_player || !game->img_exit || !game->img_collect)
	{
		write(2, "Error, failed to load the texture\n, 34");
		exit(1);
	}
}
void	mlx_init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, Error, MLX init failed\n, 22);
		exitt(1);
	}
	game->win = mlx_new_window(
		game->mlx,
		game->width = TILE,
		game->height = TILE,
		"so_long");
	if(!game->win)
	{
		write(2, "Error, Window creation failed\n, 30")
		exit(1);
	}

	load_images(game);
}