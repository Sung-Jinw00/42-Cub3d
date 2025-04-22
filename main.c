/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:46:30 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/22 21:38:50 by locagnio         ###   ########.fr       */
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
		if (len_file >= 4 && ft_strcmp(av[1] + (len_file - 4), ".cub"))
			return (ft_write(2, "Error\nfile with '.cub' extension needed.\n"));
		map_infos = (t_map){0};
		if (treat_file(av[1], &map_infos))
			return (1);
	}
	return (usage_prompt());
}
