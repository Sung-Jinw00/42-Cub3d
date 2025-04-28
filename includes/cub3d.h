/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:01:51 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 18:32:10 by marvin           ###   ########.fr       */
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
# include <X11/X.h>

# include "libft.h"
# include "mlx.h"

//game settings
# ifndef MOVE_UNIT
#  define MOVE_UNIT 1.0 / 1.0
# endif

//window settings
# ifndef MLX_WIDTH
# 	define MLX_WIDTH 1400
# endif
# ifndef MLX_HEIGHT
# 	define MLX_HEIGHT 1000
# endif

// Mouse defines
# ifndef LEFT_CLICK
# 	define LEFT_CLICK 1
# endif
# ifndef SCROLL_CLICK
# 	define SCROLL_CLICK 2
# endif
# ifndef RIGHT_CLICK
# 	define RIGHT_CLICK 3
# endif
# ifndef SCROLL_UP
# 	define SCROLL_UP 4
# endif
# ifndef SCROLL_DOWN
# 	define SCROLL_DOWN 5
# endif

typedef struct s_player
{
	double	x;
	double	y;
	double	move_unit;
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
	t_mlx		mlx;
	t_player	player;
}	t_map;

//parse and treat file
int		path_is_valid(char *pathname);
char	**get_elem(t_map *map, int elem);
int		treat_file(char *map_name, t_map *map_infos);
int		treat_map(char *map, int i, t_map *map_datas);

//player
int		only_one_player(t_map *map);
void	actualise_player_pos(t_player *p, int key);
int		is_valid_move(char **map_array, t_player p, int key);

//print
int		usage_prompt(void);
void	ft_error(char *msg);

//mlx
int		set_mlx(t_mlx *mlx, char *win_title);

//controls
void	mlx_hooks(t_map *map);

//debug
void	print_map(t_map *map);

//free
void	free_map(t_map *map);

#endif