/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:47:09 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 20:57:11 by marvin           ###   ########.fr       */
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

int	get_rgb(t_map *map_inf, char *info, int elem, int j)
{
	int	*rgb;
	int	i;

	i = 0;
	rgb = NULL;
	if (elem == 4)
		rgb = map_inf->f_rgb;
	else if (elem == 5)
		rgb = map_inf->c_rgb;
	while (rgb && j < 3)
	{
		rgb[j++] = ft_natoi(info, &i);
		if (!ft_isnum(info[i - 1]) || rgb[j - 1] > 255 || rgb[j - 1] < 0)
			return (ft_write(2, "Error\nInvalid RGB color.\n"), 0);
		i++;
	}
	while (info[i] != '\n')
		if (ft_isnum(info[i++]))
			return (ft_write(2, "Error\nToo many RGB colors.\n"), 0);
	return (1);
}

/* get the valid elements in the structure */
static int	get_map_infos(t_map *map_inf, char *info, int elem, int j)
{
	int	len_line;

	len_line = ft_strclen(info, '\n');
	if (elem < 4 && len_line < 4)
		return (ft_write(2, "Error\nNo informations for an elem.\n"), 0);
	if (elem < 4)
		len_line = ft_strclen(info + 3, '\n');
	if (elem == 0)
		map_inf->no_path = ft_strndup(info + 3, len_line);
	else if (elem == 1)
		map_inf->so_path = ft_strndup(info + 3, len_line);
	else if (elem == 2)
		map_inf->we_path = ft_strndup(info + 3, len_line);
	else if (elem == 3)
		map_inf->ea_path = ft_strndup(info + 3, len_line);
	else if ((elem == 4 || elem == 5) && !get_rgb(map_inf, info + 2, elem, j))
		return (0);
	if (ft_str_charset(map_inf->no_path, "\a\b\t\n\v\f ")
		|| ft_str_charset(map_inf->so_path, "\a\b\t\n\v\f ")
		|| ft_str_charset(map_inf->we_path, "\a\b\t\n\v\f ")
		|| ft_str_charset(map_inf->ea_path, "\a\b\t\n\v\f "))
		return (ft_write(2, "Error\nInvalid path to texture.\n"), 0);
	return (1);
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
		{
			if (!get_map_infos(map_inf, file_infos + *i, j++, 0))
				return (0);
		}
		else
			return (ft_write(2, "Error\nElements aren't in right order.\n"), 0);
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
		return (free(file_infos), 1);
	while (file_infos[i] && file_infos[i] != '\n')
		i++;
	while (file_infos[i] && !multi_charcmp(file_infos[i], "01NSEW "))
		i++;
	if (!file_infos[i])
	{
		ft_free(&file_infos);
		return (ft_write(2, "Error\nNo map given.\n"));
	}
	map_infos->map = treat_map(file_infos + i, -1, 0, map_infos);
	ft_free(&file_infos);
	if (!map_infos->map)
		return (1);
	return (0);
}
