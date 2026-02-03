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
		ft_printf("Error, the map is not rectangular\n");
		return (1);
	}
	if (!check_walls(map))
	{
		ft_printf("Error, the map is not closed by walls\n");
		return (1);
	}
	if (check_chars(map) == 0)
	{
		ft_printf("Error, wrong characters found in map or ");
		ft_printf("needed 1 exit, 1 starting position ");
		ft_printf("and at least 1 collectible\n");
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
		if (line_len(map[i]) == 0 && !map[i + 1])
			return (1);
		if (line_len(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	height;
	int	width;

	if (!map || !map[0])
		return (0);
	height = 0;
	while (map[height] && line_len(map[height]) > 0)
		height++;
	if (height < 3)
		return (0);
	width = line_len(map[0]);
	if (width < 3)
		return (0);
	if (!wall_parse(height, width, map))
		return (0);
	return (1);
}

int	wall_parse(int height, int width, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i < height - 2)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
