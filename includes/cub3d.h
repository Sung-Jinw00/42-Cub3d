/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:01:51 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/30 17:28:28 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h> // open
# include <stdio.h> // printf, perror
# include <unistd.h> // read, write, close
# include <stdlib.h> // malloc, free, exit
# include <string.h> // strerror
# include <X11/X.h>
# include <X11/keysym.h>

# include "mlx.h"
# include "libft.h"

//game settings
# ifndef SPEED
#  define SPEED			(1.0 / 15.0)
# endif

//window settings
# ifndef WIN_WIDTH
#  define WIN_WIDTH		1400
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT	1000
# endif

// Mouse defines
# define LEFT_CLICK		1
# define SCROLL_CLICK	2
# define RIGHT_CLICK	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

typedef struct s_player
{
	double	x;
	double	y;
	double	rotation;
	double	direction_x;
	double	direction_y;	
	double	mvt_speed;
}	t_player;

typedef struct s_window
{
	char	*addr;
	void	*img_id;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}	t_window;

typedef struct s_mlx
{
	void		*init;
	void		*window;
	t_window	img;
}	t_mlx;

typedef struct s_map
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			f_rgb[3];
	int			c_rgb[3];
	char		*map;
	char		**map_array;
	int			w_map;
	int			h_map;
}	t_map;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
}	t_game;

//parse and treat file
int		path_is_valid(char *pathname);
char	**get_elem(t_map *map, int elem);
int		treat_file(char *map_name, t_game *game);
int		treat_map(char *map, int i, t_game *game);

//player
int		only_one_player(t_game *game);
void	actualise_player_pos(char **map_array, t_player p, t_player *ptr_p,
    		int key);

//print
int		usage_prompt(void);
void	ft_error(char *msg);

//mlx
int		set_mlx(t_mlx *mlx, char *win_title);

//controls
void	init_hooks(t_game *game);

//debug
void	print_map(t_map *map);

//free
void	free_mlx(t_mlx *mlx);
void	free_map(t_map *map);
void	free_game(t_game *game);

#endif