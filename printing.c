/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:56:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 18:45:05 by marvin           ###   ########.fr       */
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

void	print_map(t_map *m)
{
	if (!m)
		return ;
	if (m->no_path)
		printf("no_path = %s\n", m->no_path);
	else
		printf("no_path = (null)\n");
	if (m->so_path)
		printf("so_path = %s\n", m->so_path);
	else
		printf("so_path = (null)\n");
	if (m->we_path)
		printf("we_path = %s\n", m->we_path);
	else
		printf("we_path = (null)\n");
	if (m->ea_path)
		printf("ea_path = %s\n", m->ea_path);
	else
		printf("ea_path = (null)\n");
	printf("f_rgb = {%d, %d, %d}\n", m->f_rgb[0], m->f_rgb[1], m->f_rgb[2]);
	printf("c_rgb = {%d, %d, %d}\n", m->c_rgb[0], m->c_rgb[1], m->c_rgb[2]);
	printf("h_map = %d\nl_map = %d\n", m->h_map, m->w_map);
	if (m->map)
		printf("map :\n%s\n", m->map);
	else
		printf("map = (null)\n");
}
