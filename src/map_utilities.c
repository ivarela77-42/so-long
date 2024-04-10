/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:34:57 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/28 19:51:24 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map map)
{
	int	y;

	y = -1;
	while (map.map[++y])
		free(map.map[y]);
	free(map.map);
	map.map = NULL;
}

void	print_image_in_map(int c, t_game *game, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(
			game->mlx, game->mlx_win, game->image.wall, j * 64, i * 64);
	if (c == '0')
		mlx_put_image_to_window(
			game->mlx, game->mlx_win, game->image.floor, j * 64, i * 64);
	if (c == 'P')
	{
		// Inicializa jugador
		game->player.y = i;
		game->player.x = j;
		// game->map.map[i][j] = '0';
		mlx_put_image_to_window(
			game->mlx, game->mlx_win, game->image.player, j * 64, i * 64);
	}
	if (c == 'C')
		mlx_put_image_to_window(
			game->mlx, game->mlx_win, game->image.collectable, j * 64, i * 64);
	if (c == 'E')
		mlx_put_image_to_window(
			game->mlx, game->mlx_win, game->image.exit, j * 64, i * 64);
}

void	print_map_in_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	
	while (i < game->map.y)
	{
		j = 0;
		while (j < game->map.x)
		{
			
			print_image_in_map(game->map.map[i][j], game, i, j);
			j++;
		}
		i++;
	}
	print_scoreboard(game);
}
