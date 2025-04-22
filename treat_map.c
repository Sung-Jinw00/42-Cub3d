/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:47:09 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 00:41:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*formated_map(char **map_array, int len_map_arr, int *len_strings)
{
	char	*formated_map;
	char	*spaces;
	int		greatest_len;
	int		i;

	i = -1;
	greatest_len = len_strings[++i];
	while (++i < len_map_arr)
		if (greatest_len < len_strings[i])
			greatest_len = len_strings[i];
	formated_map = ft_calloc(sizeof(char), len_map_arr * greatest_len + 1);
	spaces = ft_calloc(sizeof(char), greatest_len + 1);
	if (!formated_map || !spaces)
		return (free(len_strings), free_array(&map_array),
			ft_write(2, "Error\nFailed creating formated map.\n"), NULL);
	memset(spaces, ' ', greatest_len);
	i = -1;
	while (map_array[++i])
	{
		ft_strcat(formated_map, map_array[i]);
		if (len_strings[i] < greatest_len)
			ft_strncat(formated_map, spaces, greatest_len - len_strings[i]);
	}
	multi_free("1, 1, 2", spaces, len_strings, map_array, NULL);
	return (ft_replace_from_string(formated_map, " ", "1", 1));
}

/* if a space is not surrounded by the limits of the map, it return 0 */
int	check_limits(char **map_array, int len_map_arr, int *len_strings)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < len_map_arr)
	{
		while (map_array[j][i])
		{
			if (map_array[j][i] == ' '
				&& ((i < len_strings[j - 1]
						&& !multi_charcmp(map_array[j + 1][i], "1 "))
					|| (i < len_strings[j + 1]
						&& !multi_charcmp(map_array[j - 1][i], "1 "))
					|| (map_array[j][i + 1]
						&& !multi_charcmp(map_array[j][i + 1], "1 "))
					|| (i > 0
						&& !multi_charcmp(map_array[j][i - 1], "1 "))))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

/* check the sides of map to see if it's well bordered */
int	check_sides(char **map_array, int len_map_arr, int *len_strings)
{
	int	j;

	j = 1;
	while (j < len_map_arr)
	{
		if (!(map_array[j][0] == ' ' || map_array[j][0] == '1')
			|| !(map_array[j][len_strings[j] - 1] == ' '
			|| map_array[j][len_strings[j] - 1] == '1'))
			return (0);
		j++;
	}
	return (1);
}

char	*treat_map(char *map, int i, int j)
{
	char	**map_array;
	int		len_map_arr;
	int		*len_strings;

	if (!ft_str_isformat(map, "01NSEW \n\r"))
		return (ft_write(2, "Error\nWrong format used.\n"), NULL);
	map_array = ft_split(map, "\n\r");
	if (!map_array)
		return (ft_write(2, "Error\nFail splitting map.\n"), NULL);
	len_map_arr = ft_count_words(map_array);
	len_strings = malloc(sizeof(int) * len_map_arr);
	if (!len_strings)
		return (free_array(&map_array),
			ft_write(2, "Error\nFail getting len of strings.\n"), NULL);
	i = -1;
	while (map_array[++i])
		len_strings[i] = ft_strlen(map_array[i]);
	i = 0;
	if (!ft_str_isformat(map_array[j++], "1 ")
		|| !ft_str_isformat(map_array[len_map_arr - 1], "1 ")
		|| !check_sides(map_array, len_map_arr, len_strings)
		|| !check_limits(map_array, len_map_arr, len_strings))
		return (free(len_strings), free_array(&map_array),
			ft_write(2, "Error\nMap is invalid.\n"), NULL);
	return (formated_map(map_array, len_map_arr, len_strings));
}
