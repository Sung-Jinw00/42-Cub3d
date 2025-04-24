/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:47:09 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 21:07:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*formated_map(char **map_array, t_map *map, int *len_strings, int i)
{
	char	*formated_map;
	char	*spaces;

	map->w_map = ft_max_array(len_strings, map->h_map);
	formated_map = ft_calloc(sizeof(char),
			map->h_map * map->w_map + map->w_map - 1 + 1);
	spaces = ft_calloc(sizeof(char), map->w_map + 1);
	if (!formated_map || !spaces)
		return (free(len_strings), free_array(&map_array),
			ft_write(2, "Error\nFailed creating formated map.\n"), NULL);
	memset(spaces, ' ', map->w_map);
	i = -1;
	while (map_array[++i])
	{
		ft_strcat(formated_map, map_array[i]);
		if (i < map->h_map)
			ft_strncat(formated_map, spaces, map->w_map - len_strings[i]);
		if (i < map->h_map - 1)
			ft_strcat(formated_map, "\n");
	}
	multi_free("1, 1, 2", spaces, len_strings, map_array, NULL);
	return (ft_replace_from_string(formated_map, " ", "1", 1));
}

/* check the 9 boxs around a space and see if it's surrounded with 1 or spaces*/
static int	walls_around(int *len_strings, char **map_array, int i, int j)
{
	if ((map_array[j + 1] && i < len_strings[j + 1]
			&& !ft_strchr("1 ", map_array[j + 1][i]))
	|| (map_array[j + 1] && i + 1 < len_strings[j + 1]
		&& !ft_strchr("1 ", map_array[j + 1][i + 1]))
	|| (map_array[j + 1] && i > 0 && i - 1 < len_strings[j + 1]
		&& !ft_strchr("1", map_array[j + 1][i - 1]))
	|| (j > 0 && i < len_strings[j - 1]
		&& !ft_strchr("1 ", map_array[j - 1][i]))
	|| (j > 0 && i + 1 < len_strings[j - 1]
		&& !ft_strchr("1 ", map_array[j - 1][i + 1]))
	|| (j > 0 && i > 0 && i - 1 < len_strings[j - 1]
		&& !ft_strchr("1 ", map_array[j - 1][i - 1]))
	|| (map_array[j][i] && map_array[j][i + 1]
		&& !ft_strchr("1 ", map_array[j][i + 1]))
	|| (i > 0
		&& !ft_strchr("1 ", map_array[j][i - 1])))
		return (0);
	return (1);
}

/* if a space is not surrounded by the limits of the map, it return 0 */
static int	check_limits(char **map_array, int map_height, int *len_strings)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map_height)
	{
		while (map_array[j][i])
		{
			if (map_array[j][i] == ' '
				&& !walls_around(len_strings, map_array, i, j))
				return (0);
			i++;
			if (!map_array[j][i] && !walls_around(len_strings, map_array, i, j))
				return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}

/* check the sides of map to see if it's well bordered */
static int	check_sides(char **map_array, int map_height, int *len_strings)
{
	int	j;

	j = 1;
	while (j < map_height)
	{
		if (!(map_array[j][0] == ' ' || map_array[j][0] == '1')
			|| !(map_array[j][len_strings[j] - 1] == ' '
			|| map_array[j][len_strings[j] - 1] == '1'))
			return (0);
		j++;
	}
	return (1);
}

char	*treat_map(char *map, int i, int j, t_map *map_datas)
{
	char	**map_array;
	int		*len_strings;

	if (!ft_str_isformat(map, "01NSEW \n\r"))
		return (ft_write(2, "Error\nWrong format used.\n"), NULL);
	map_array = ft_split(map, "\n\r");
	if (!map_array)
		return (ft_write(2, "Error\nFail splitting map.\n"), NULL);
	map_datas->h_map = ft_count_words(map_array);
	len_strings = malloc(sizeof(int) * map_datas->h_map);
	if (!len_strings)
		return (free_array(&map_array),
			ft_write(2, "Error\nFail getting len of strings.\n"), NULL);
	while (map_array[++i])
		len_strings[i] = ft_strlen(map_array[i]);
	if (!ft_str_isformat(map_array[j++], "1 ")
		|| !ft_str_isformat(map_array[map_datas->h_map - 1], "1 ")
		|| !check_sides(map_array, map_datas->h_map, len_strings)
		|| !check_limits(map_array, map_datas->h_map, len_strings))
		return (free(len_strings), free_array(&map_array),
			ft_write(2, "Error\nMap is invalid.\n"), NULL);
	if (!only_one_player(map))
		return (free(len_strings), free_array(&map_array), NULL);
	return (formated_map(map_array, map_datas, len_strings, -1));
}
