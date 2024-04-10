/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:58:26 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/29 12:23:59 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		file_error;
	int		map_error;
	t_game	game;
	// char	*mlx;
	// char	**win;
	// void	*img;
	// char	*relative_path = "../images/wall.xpm";
	// int		img_width;
	// int		img_height;


	// printf("%i\n", check_errors(argc, argv[1], &game));
	file_error = check_file_errors(argc, argv[1], &game);
	if (file_error != 0)
		print_error(file_error);
	else{
		map_error = check_map_errors(argc, argv[1], &game);
		if (map_error != 0)
			print_error(map_error);
		else
		{
			game.mlx = mlx_init();
			game.mlx_win = mlx_new_window(game.mlx, game.map.x * 64, game.map.y * 64, "Pacman Luigi");

			hooks_injection(&game);
			images_injection(&game);
			game.player.moves = 0;
			game.player.collected = 0;
			print_map_in_window(&game);

			// move_player(&game);


			mlx_loop(game.mlx);
			// ft_putstr_fd("A jugar...\n", 1);
			// printf("Path:%s\n", game.map.path);
			// printf("X:%i\n", game.map.x);
			// printf("Y:%i\n", game.map.y);
			// ft_putstr_fd("Mapa del juego:\n", 1);
			// ft_putstr_fd("---------------\n", 1);
			// while (map_error < 4)
			// {
			// 	ft_putstr_fd(game.map.map[map_error], 1);
			// 	map_error++;
			// }
			// ft_putstr_fd("\n", 1);
		}
	}
	

	
	// ft_bzero(&game, sizeof(t_game));
	// (void) argv;

	// if (!check_errors(argc, argv[1], &game))
	// {
	// 	ft_putstr_fd("A jugar...\n", 1);
	// 	// printf("Mapa: %s\n", game.map.path);
	// 	// printf("X   : %i\n", game.map.x);
	// 	// printf("Y   : %i\n", game.map.y);
	// }
	// printf("Res: %s\n", str1);
	// printf("Res: %li\n", ft_strlcat(str1, str2, 13));
	// printf("Res: %s\n", str1);

	/* error = check_errors(argc, argv[1], &game);
	if (error)
	{
		ft_putstr_fd(error, 2);
		free(error);
	}
	else{ */
	// printf("%i\n", check_errors(argc, argv[1], &game));
	// if (check_errors != 1)
	// {
	// 	// TODO: mlx
	// 	ft_putstr_fd("A jugar...\n", 1);
	// 	printf("%sMapa    -> \n", game.map.path);
	// 	printf("%iLongitud-> \n", game.map.x);
	// 	printf("%iAltura  -> \n", game.map.y);
	// 	mlx = mlx_init();
	// 	win = mlx_new_window(mlx, 500, 500, "Mi Ventana");
	// 	mlx_hook(win, 17, 0, close_window, NULL);
	// 	mlx_loop(mlx);
		
	// }
    return (0);
}