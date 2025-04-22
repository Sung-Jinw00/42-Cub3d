/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:47:09 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 01:14:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_elem_infos(char *elems[])
{
	elems[0] = "NO";
	elems[1] = "SO";
	elems[2] = "WE";
	elems[3] = "EA";
	elems[4] = "F";
	elems[5] = "C";
}

/* get the valid elements in the structure */
static void	get_map_infos(t_map *map_inf, char *info, int elem, int j)
{
	int	*rgb;
	int	i;

	if (elem == 0)
		map_inf->no_path = ft_strndup(info + 3, ft_strclen(info, '\n'));
	else if (elem == 1)
		map_inf->so_path = ft_strndup(info + 3, ft_strclen(info, '\n'));
	else if (elem == 2)
		map_inf->we_path = ft_strndup(info + 3, ft_strclen(info, '\n'));
	else if (elem == 3)
		map_inf->ea_path = ft_strndup(info + 3, ft_strclen(info, '\n'));
	rgb = NULL;
	if (elem == 4)
		rgb = map_inf->f_rgb;
	else if (elem == 5)
		rgb = map_inf->c_rgb;
	i = 3;
	while (rgb && j < 3)
	{
		rgb[j++] = ft_natoi(info, &i);
		i++;
	}
}

/* check if the elements are valid and get them */
static int	check_elems(char *file_infos, int *i, char *elems[], t_map *map_inf)
{
	int	j;
	int	count;

	count = 6;
	j = 0;
	while (file_infos[*i] && count)
	{
		while (file_infos[*i] && file_infos[*i] == '\n')
			(*i)++;
		if (file_infos[*i]
			&& !ft_strncmp(file_infos + *i, elems[j], ft_strlen(elems[j])))
			get_map_infos(map_inf, file_infos + *i, j++, 0);
		else
		{
			free_map(map_inf);
			return (ft_write(2, "Error\nElements aren't in right order.\n"), 0);
		}
		count--;
		while (file_infos[*i] && file_infos[*i] != '\n')
			(*i)++;
	}
	if (count != 0)
		return (ft_write(2, "Error\nLacking elements for map.\n"), 0);
	return (1);
}

int	treat_file(char *map_name, t_map *map_infos)
{
	char	*file_infos;
	char	*elems[6];
	int		i;

	i = 0;
	init_elem_infos(elems);
	file_infos = ft_read_file(map_name);
	if (!file_infos || !file_infos[0])
		return (ft_write(2, "Error\nEmpty file.\n"));
	else if (!check_elems(file_infos, &i, elems, map_infos))
		return (1);
	while (file_infos[i] && file_infos[i] != '\n')
		i++;
	while (file_infos[i] && !multi_charcmp(file_infos[i], "01NSEW "))
		i++;
	if (!file_infos[i])
	{
		ft_free(&file_infos);
		return (ft_write(2, "Error\nNo map given.\n"));
	}
	map_infos->map = treat_map(file_infos + i, 0, 0, map_infos);
	ft_free(&file_infos);
	if (!map_infos->map)
		return (free_map(map_infos), 1);
	return (0);
}
