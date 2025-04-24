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

# include "libft.h"

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		f_rgb[3];
	int		c_rgb[3];
	char	*map;
	char	**map_array;
	int		w_map;
	int		h_map;
}	t_map;

//main
int		main(int ac, char **av);

//parse and treat file
int		treat_file(char *map_name, t_map *map_infos);
char	*treat_map(char *map, int i, int j, t_map *map_datas);

//player
int	only_one_player(char *map);

//print
int		usage_prompt(void);
void	error(char *msg);

void	print_map(t_map *map);

//free
void	free_map(t_map *map);

#endif