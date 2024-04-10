/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:00:48 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/29 13:37:00 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	images_injection(t_game *game)
{
	int	x;
	int	y;
	
	
	
	
	
	game->image.wall = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
	game->image.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &x, &y);

	game->image.collectable = mlx_xpm_file_to_image(
			game->mlx, COLLECTABLE, &x, &y);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->image.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &x, &y);
	if (!game->image.player)
				exit(0);
}