/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:13:49 by echarmai          #+#    #+#             */
/*   Updated: 2026/01/26 12:44:05 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_checker(char **map)
{
	if (!check_rectangle(map))
	{
		write(2, "Error, the map is not rectangular\n", 34);
		return (1);
	}
	if (!check_walls(map))
	{
		write(2, "Error, the map is not closed by walls\n", 37);
		return (1);
	}
	return (0);
}

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
		i++;
	return (i);
}

int	check_rectangle(char **map)
{
	int	i;
	int	len;

	if (!map || !map[0])
		return (0);
	len = line_len(map[0]);
	i = 1;
	while (map[i])
	{
		if (line_len(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	if (!map || !map[0])
		return (0);

	height = 0;
	while (map[height])
		height++;
	width = line_len(map[0]);
	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
