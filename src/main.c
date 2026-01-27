/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:05:10 by echarmai          #+#    #+#             */
/*   Updated: 2026/01/26 13:20:19 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_map_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error, Wrong number of argument\n", 32);
		return (1);
	}
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);

	game.height = get_map_height(game.map);
	game.width = get_map_width(game.map);
	game.moves = 0;

	mlx_init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}

