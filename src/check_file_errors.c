/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:39:34 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/29 17:10:08 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Imprimir errores */
void	print_error(int code)
{
	t_error				errors[12];
	long unsigned int	i;

	errors[0] = (t_error){100, "Error\nInvalid number of arguments.\n"};
	errors[1] = (t_error){101, "Error\nMap must have '.ber' extension.\n"};
	errors[2] = (t_error){102, "Error\nMap not found.\n"};
	errors[3] = (t_error){103, "Error\nMap is empty.\n"};
	errors[4] = (t_error){104, "Error\nMap on x is irregular.\n"};
	errors[5] = (t_error){105, "Error\nMap not created.\n"};
	errors[6] = (t_error){106, "Error\nMap must be rectangular.\n"};
	errors[7] = (t_error){107, "Error\nBad structure, wrong perimeter(1).\n"};
	errors[8] = (t_error){
		108, "Error\nBad structure, fix exit doors(E = 1).\n"};
	errors[9] = (t_error){
		109, "Error\nBad structure, fix player(P = 1).\n"};
	errors[10] = (t_error){
		110, "Error\nBad structure, invalid character(P, E, C, 1, 0).\n"};
	errors[11] = (t_error){
		111, "Error\nBad structure, fix collectables(C min. 1).\n"};
	i = 0;
	while (i < (sizeof(errors) / sizeof(errors[0]) - 1)
		&& errors[i].code != code)
		i++;
	ft_putstr_fd(errors[i].message, 2);
}

/* Comprueba estensión .ber */
int	is_wrong_extension(char *argv)
{
	return (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4));
}

/* Valida que sea un mapa valido y crea nombre,map.x y map.y */
int	is_wrong_file(char *argv, t_game *game)
{
	int		fd;
	char	*line;

	chdir("maps");
	game->map.path = argv;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (102);
	line = get_next_line(fd);
	if (!line)
		return (103);
	game->map.x = ft_strlen(line) - 1;
	game->map.y = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if ((int)ft_strlen(line) != game->map.x)
			return (104);
		game->map.y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/* Crea el mapa y lo rellena con los datos del archivo */
int	set_config_map(char *argv, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (102);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	if (!game->map.map)
		return (105);
	line = get_next_line(fd);
	if (!line)
		return (103);
	i = 0;
	while (i < game->map.y)
	{
		game->map.map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
	return (0);
}

/* Valida errores de archivo y creacion de mapa */
int	check_file_errors(int argc, char *argv, t_game *game)
{
	int	error;

	if (argc != 2)
		return (100);
	if (is_wrong_extension(argv))
		return (101);
	error = is_wrong_file(argv, game);
	if (game->map.x == game->map.y)
		return (106);
	if (error != 0)
		return (error);
	error = set_config_map(argv, game);
	if (error != 0)
		return (error);
	return (0);
}
