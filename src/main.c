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

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
		return (1);

	map = read_map(argv[1]);
	if (!map)
		return (1);
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	return (0);

	char **map_copy;

	map_copy = copy_map(map);
	if (!check_flood(map_copy))
	{
		write(2, "Error, the map is not solvable\n", 31);
		return (1);
	}
}
