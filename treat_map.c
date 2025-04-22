/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:47:09 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/22 21:42:01 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* if a space is not surrounded by the limits of the map, it return 0 */
int	check_inside(char **map_array, int len_map_arr, int prev_len, int next_len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < len_map_arr)
	{
		prev_len = ft_strlen(map_array[j - 1]) - 1;
		next_len = ft_strlen(map_array[j + 1]) - 1;
		while (map_array[j][i])
		{
			if (map_array[j][i] == ' '
				&& ((i <= prev_len && !multi_charcmp(map_array[j + 1][i], "1 "))
					|| (i <= next_len
						&& !multi_charcmp(map_array[j - 1][i], "1 "))
					|| (map_array[j][i + 1]
						&& !multi_charcmp(map_array[j][i + 1], "1 "))
					|| (i > 0 && !multi_charcmp(map_array[j][i - 1], "1 "))))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

/* check the right side of the map, if it's well connected */
int	check_right_side(char **map_array, int len_map_arr)
{
	int	i;
	int	previous_len;
	int	j;

	j = 1;
	i = ft_strlen(map_array[j]) - 1;
	while (j < len_map_arr && map_array[j][i])
	{
		previous_len = ft_strlen(map_array[0]) - 1;
		while (previous_len < i && i >= 0 && map_array[j - 1][i] != '1')
			i--;
		if (map_array[j][i] != '1')
			return (0);
		while (map_array[j][i] == '1')
			i++;
		if (!map_array[j][i] != '1' || map_array[j][i] != '1')
			i--;
		j++;
	}
	return (1);
}

/* check the left side of the map, if it's well connected */
int	check_left_side(char **map_array, int len_map_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < len_map_arr && map_array[j][i])
	{
		while (map_array[j - 1][i] != '1')
			i++;
		if (map_array[j][i] != '1')
			return (0);
		while (i >= 0 && map_array[j][i] == '1')
			i--;
		if (map_array[j][i] != '1')
			i++;
		j++;
	}
	return (1);
}

char	*treat_map(char *map)
{
	char	**map_array;
	int		len_map_arr;
	int		i;
	int		j;

	if (ft_str_isformat(map, "01NSEW \n"))
		return (ft_write(2, "Error\nWrong format used.\n"), NULL);
	map_array = ft_split(map, "\n");
	if (!map_array)
		return (ft_write(2, "Error\nFail splitting map.\n"), NULL);
	len_map_arr = ft_count_words(map_array);
	i = 0;
	j = 0;
	if (!ft_str_isformat(map_array[j++], "1 ")
		|| !ft_str_isformat(map_array[len_map_arr], "1 ")
		|| !check_left_side(map_array, len_map_arr)
		|| !check_right_side(map_array, len_map_arr)
		|| !check_inside(map_array, len_map_arr, 0, 0))
		return (ft_write(2, "Error\nMap is invalid.\n"), NULL);
	return (ft_strdup(map));
}
