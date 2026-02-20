/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:59:53 by echarmai          #+#    #+#             */
/*   Updated: 2026/01/26 12:49:18 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_line(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open (filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nNo such file in directory");
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_map(char *filename)
{
	char	**map;
	int		lines;
	int		fd;
	int		i;

	lines = count_line(filename);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (free_grid(map), NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	map[i] = get_next_line(fd);
	while (i < lines)
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n' && map[i][j] != '\r')
		{
			if (!ft_strchr("01PCE", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (check_min_chars(map));
}

void	count_chars(char **map, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n' && map[i][j] != '\r')
		{
			if (map[i][j] == 'P')
				(*p)++;
			if (map[i][j] == 'E')
				(*e)++;
			if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}
