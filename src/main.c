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
	while (map[0][i] && map[0][i] != '\n')
		i++;
	return (i - 1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "Error, Wrong number of argument\n", 32);
		return (0);
	}
	game.map = read_map(argv[1]);
	if (!game.map)
		return (0);
	if (map_checker(game.map))
		return (0);
	if (flood(game.map))
		return (0);
	game.height = get_map_height(game.map);
	game.width = get_map_width(game.map);
	game.moves = -1;
	mlx_init_game(&game);
	load_images(&game);
	find_player_and_collectibles(&game);
	mlx_key_hook(game.win, handle_key, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (-1);
}

int	check_min_chars(char **map)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	count_chars(map, &p, &e, &c);
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}
