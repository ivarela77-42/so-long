/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:23:48 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/03/29 13:26:51 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/includes/libft.h"
# include "../lib/mlx_linux/mlx.h"
# include <fcntl.h>
# define WALL "../images/wall.2.xpm"
# define PLAYER "../images/playe.1D.xpm"
# define COLLECTABLE "../images/coin.4.xpm"
# define EXIT "../images/exit.2.xpm"
# define FLOOR "../images/floor.1.xpm"

# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

typedef struct s_error
{
	int		code;
	char	*message;
}			t_error;

typedef struct s_map
{
	char		*path;
	char		**map;
	int			x;
	int			y;
	int			player;
	int			exit;
	int			collectables;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
// 	// int			tokens;
	int			collected;
	int			moves;
// 	// bool		exit;
}				t_player;	

typedef struct s_image
{
	void		*collectable;
	void		*player;
	void		*wall;
	void		*floor;
	void		*exit;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_image		image;
	t_player	player;
}	t_game;

void	print_error(int code);
int		check_file_errors(int argc, char *argv, t_game *game);
int		check_map_errors(int argc, char *argv, t_game *game);
void	hooks_injection(t_game *game);
void	images_injection(t_game *game);
void	print_map_in_window(t_game *game);
void	free_map(t_map map);
void	move_player(t_game *game, int i, int j);
void	print_scoreboard(t_game *game);

#endif