/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:56:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/22 18:29:26 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	usage_prompt(void)
{
	ft_write(2, "Hello there !\nThis program should take a describing scene");
	ft_write(2, " file with '.cub' extension.\n The file should only be");
	ft_write(2, " formated with the following characters :\n\t- 0 : For empty");
	ft_write(2, " spaces.\n\t- 1 : For walls. The map should be closed with");
	ft_write(2, " walls.\n\t- N, S, E or W : The starting position");
	ft_write(2, " and orientation of the player. Only one is accepted.\n");
	return (1);
}
