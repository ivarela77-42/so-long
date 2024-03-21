/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:58:26 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/21 22:23:53 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../lib/minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlxPb;
	void	*mlx_win;
	void	*image;
	int x;
	int y;

	
	mlxPb = mlx_init();
	mlx_win = mlx_new_window(mlxPb, 1920, 1080, "Hello world!");
	image =mlx_xpm_file_to_image(mlxPb, "Proyectos-Cursus/so-long/src/coins.xpm", &(x), &(y));
	mlx_put_image_to_window(mlxPb, mlx_win, image, (x * 64),
		(y * 64));
	// (void) mlx_win;
	// (void) mlx_win;
	mlx_loop(mlxPb); 
	return (0);
}