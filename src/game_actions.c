/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:24:51 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/29 12:06:24 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_scoreboard(t_game *game)
{
	int		x;
	int		y;

	x = -1;
	while (++x < 128)
	{
		y = -1;
		while (++y < 64)
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x09508F);
	}
	mlx_string_put(game->mlx, game->mlx_win, 8, 24, 0xFFFFFF, "Collectables :");
	mlx_string_put(game->mlx, game->mlx_win, 100, 24, 0xFFFFFF, ft_itoa(game->player.collected));
	mlx_string_put(game->mlx, game->mlx_win, 106, 24, 0xFFFFFF, "/");
	mlx_string_put(game->mlx, game->mlx_win, 112, 24, 0xFFFFFF, ft_itoa(game->map.collectables));
	mlx_string_put(game->mlx, game->mlx_win, 8, 48, 0xFFFFFF, "Moves        : ");
	mlx_string_put(game->mlx, game->mlx_win, 106, 48, 0xFFFFFF, ft_itoa(game->player.moves));
}


void	move_player(t_game *game, int i, int j)
{
	int ppx;
	int ppy;

	ppx = game->player.x;
	ppy = game->player.y;
	if (game->map.map[ppy + i][ppx + j] == '1')
		return ;
	if (game->map.map[ppy + i][ppx + j] == '0')
	{
		game->player.moves += 1;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y + i][game->player.x + j] = 'P';
		game->player.y += i;
		game->player.x += j;
		print_map_in_window(game);
	}
	if (game->map.map[ppy + i][ppx + j] == 'C')
	{
		game->player.moves += 1;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y + i][game->player.x + j] = 'P';
		game->player.y += i;
		game->player.x += j;
		game->player.collected += 1;
		print_map_in_window(game);
	}
	// TODO: Salida con todos los items sino error
	if (game->map.map[ppy + i][ppx + j] == 'E')
	{
		game->player.moves += 1;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y + i][game->player.x + j] = 'P';
		game->player.y += i;
		game->player.x += j;
		print_map_in_window(game);
	}

	print_scoreboard(game);
}