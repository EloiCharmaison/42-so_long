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
	char	c;

	count = 0;
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count + 1);
}

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;

	line = malloc(10000);
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			break ;
		line[i++] = c;
	}
	if (i == 0 && c != '\n')
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

char	**read_map(char *filename)
{
	char	**map;
	int		lines;
	int		fd;
	int		i;

	lines = count_line(filename);
	if (lines == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = read_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
	return (map);
}
