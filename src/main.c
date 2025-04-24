/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:30 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/23 20:56:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		len_file;
	t_map	map_infos;

	if (ac == 2)
	{
		len_file = ft_strlen(av[1]);
		if (len_file <= 4 || ft_strcmp(av[1] + (len_file - 4), ".cub"))
			return (error("file with '.cub' extension needed.\n"), 1);
		map_infos = (t_map){0};
		if (treat_file(av[1], &map_infos))
		{
			free_map(&map_infos);
			return (1);
		}
		free_map(&map_infos);
		return (0);
	}
	usage_prompt();
	return (0);
}
