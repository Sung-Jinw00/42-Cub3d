/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:53:48 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/24 21:32:34 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_elem(t_map *map, int elem)
{
	if (elem == 0)
		return (&map->no_path);
	else if (elem == 1)
		return (&map->so_path);
	else if (elem == 2)
		return (&map->we_path);
	else if (elem == 3)
		return (&map->ea_path);
	return (NULL);
}

int	path_is_valid(char *pathname)
{
	int		fd;
	int		bytes_read;
	char	test_buffer[10];

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (error("Path for elem is invalid\n"), 0);
	bytes_read = read(fd, test_buffer, sizeof(test_buffer));
	if (bytes_read == -1)
		return (error("Path for elem is not leading to a file\n"), 0);
	if (!bytes_read)
		return (error("Path for elem leads to empty file\n"), 0);
	return (1);
}
