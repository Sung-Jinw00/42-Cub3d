/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:56:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 01:15:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	usage_prompt(void)
{
	ft_write(2, "Hello there !\nThis program should take a describing scene");
	ft_write(2, " file with '.cub' extension.\n\n The file should only be");
	ft_write(2, " formated with the following characters :\n\t- 0 : For empty");
	ft_write(2, " spaces.\n\t- 1 : For walls. The map should be closed with");
	ft_write(2, " walls.\n\t- N, S, E or W : The starting position");
	ft_write(2, " and orientation of the player. Only one is accepted.\n\t");
	ft_write(2, "- Spaces : You can put spaces to change the shape of the ");
	ft_write(2, "map, if there's spaces inside the\n\t\t   map, they should ");
	ft_write(2, "be surrounded with walls to be valid.\n\n");
	return (1);
}

void	free_map(t_map *map)
{
	if (map->no_path)
		ft_free(&map->no_path);
	if (map->so_path)
		ft_free(&map->so_path);
	if (map->we_path)
		ft_free(&map->we_path);
	if (map->ea_path)
		ft_free(&map->ea_path);
	if (map->map)
		ft_free(&map->map);
}
