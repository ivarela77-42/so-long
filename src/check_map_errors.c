/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:39:34 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/28 16:33:01 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_game_items(char c, t_game *game, int is_last)
{
	if (c == 'E')
		game->map.exit++;
	if (c == 'P')
		game->map.player++;
	if (c == 'C')
		game->map.collectables++;
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		return (110);
	if (is_last == 1)
	{
		if (game->map.collectables == 0)
			return (111);
		if (game->map.exit  == 0 || game->map.exit > 1)
			return (108);
		if (game->map.player == 0 || game->map.player > 1)
			return (109);
	}
	return (0);
}

int	step_by_step_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->map.collectables = 0;
	while (i < game->map.y)
	{
		j = 0;
		while (j < game->map.x)
		{
			if ((i == 0 || i == game->map.y - 1
					|| j == 0 || j == game->map.x - 1)
				&& game->map.map[i][j] != '1')
				return (107);
			else if (i > 0 && i < game->map.y - 1
				&& j > 0 && j < game->map.x - 1
				&& check_game_items(game->map.map[i][j], game, 0) != 0)
				return (check_game_items(game->map.map[i][j], game, 0));
			j++;
		}
		i++;
	}
	return (check_game_items(game->map.map[i - 1][j - 1], game, 1));
}

//TODO: Validar camino valido

/* Valida errores de archivo y creacion de mapa */
int	check_map_errors(int argc, char *argv, t_game *game)
{
	int	error;

	(void) argc;
	(void) argv;
	(void) game;
	error = step_by_step_map(game);
	if (error != 0)
		return (error);
	//TODO: crear jugador y situarlo
	return (0);
}
