/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:28:25 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/29 13:17:40 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handler_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->image.exit);
	mlx_destroy_image(game->mlx, game->image.collectable);
	mlx_destroy_image(game->mlx, game->image.floor);
	mlx_destroy_image(game->mlx, game->image.player);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}

int	handler_keyboard(int keycode, t_game *game)
{
	// printf("%i\n", keycode);
	if (keycode == Q || keycode == ESC)
		handler_close(game);
	else if (keycode == W || keycode == KEY_UP)
		move_player(game, -1, 0);
	else if (keycode == S || keycode == KEY_DOWN)
		move_player(game, 1, 0);
	else if (keycode == A || keycode == KEY_LEFT)
		move_player(game, 0, -1);
	else if (keycode == D || keycode == KEY_RIGHT)
		move_player(game, 0, 1);
	return (0);
}

void	hooks_injection(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 0, handler_close, game);
	mlx_hook(game->mlx_win, 2, 1, handler_keyboard, game);
}
