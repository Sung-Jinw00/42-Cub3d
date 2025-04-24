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

int	get_rgb(t_map *map, char *info, int elem)
{
	int	*rgb;
	int	i;
	int	j;

	i = 0;
	j = 0;
	rgb = NULL;
	if (elem == 4)
		rgb = map->f_rgb;
	else if (elem == 5)
		rgb = map->c_rgb;
	while (rgb && j < 3)
	{
		rgb[j++] = ft_natoi(info, &i);
		if (!ft_isnum(info[i - 1]) || rgb[j - 1] > 255 || rgb[j - 1] < 0)
			return (error("Invalid RGB color.\n"), 0);
		i++;
	}
	while (info[i] != '\n')
		if (ft_isnum(info[i++]))
			return (error("Too many RGB colors.\n"), 0);
	return (1);
}

/* get the valid elements in the structure */
static int	get_map_infos(t_map *map, char *info, char **elem, int elem_nb)
{
	int	len_line;

	if (elem_nb < 4)
	{
		len_line = ft_strclen(info, '\n');
		if (len_line < 4)
			return (error("No informations for an elem.\n"), 0);
		len_line = ft_strclen(info + 3, '\n');
		*elem = ft_strndup(info + 3, len_line);
		if (ft_str_charset(*elem, "\a\b\t\n\v\f "))
			return (error("Invalid path to texture.\n"), 0);
	}
	else if ((elem_nb < 6) && !get_rgb(map, info + 2, elem_nb))
		return (0);
	return (1);
}

/* check if the elements are valid and get them */
static int	check_elems(char *file_infos, int *i, char *elems[], t_map *map)
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
			if (!get_map_infos(map, file_infos + *i, get_elem(map, j), j))
				return (0);
			j++;
		}
		else
			return (error("Elements aren't in right order.\n"), 0);
		count--;
		while (file_infos[*i] && file_infos[*i] != '\n')
			(*i)++;
	}
	if (count != 0)
		return (error("Lacking elements for map.\n"), 0);
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
		return (error("Empty file.\n"), 1);
	else if (!check_elems(file_infos, &i, elems, map_infos))
		return (free(file_infos), 1);
	while (file_infos[i] && file_infos[i] != '\n')
		i++;
	while (file_infos[i] && !ft_strchr("01NSEW ", file_infos[i]))
		i++;
	if (!file_infos[i])
	{
		free(file_infos);
		return (error("No map given.\n"), 1);
	}
	map_infos->map = treat_map(file_infos + i, -1, 0, map_infos);
	free(file_infos);
	if (!map_infos->map || !map_infos->map_array)
		return (1);
	return (0);
}
