/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:18:43 by marvin            #+#    #+#             */
/*   Updated: 2026/01/30 18:18:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_and_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collectibles = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next = game->map[new_y][new_x];
	if (!check_move(game, next))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves : %d\n", game ->moves);
	render_map(game);
}

int	check_move(t_game *game, char next)
{
	if (next == '1')
		return (0);
	if (next == 'C')
		game->collectibles--;
	if (next == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf("░██████╗░░██████╗░\n\
██╔════╝░██╔════╝░\n\
██║░░██╗░██║░░██╗░\n\
██║░░╚██╗██║░░╚██╗\n\
╚██████╔╝╚██████╔╝\n\
░╚═════╝░░╚═════╝░\n");
			close_game(game);
		}
	}
	return (1);
}
