/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:36:35 by gakarbou          #+#    #+#             */
/*   Updated: 2025/05/07 12:41:42 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//might add other functions later
void	init_size_line_steps(int size_line, int steps[5])
{
	steps[0] = size_line;
	steps[1] = size_line + size_line;
	steps[2] = steps[1] + size_line;
	steps[3] = steps[2] + size_line;
	steps[4] = steps[3] + size_line;
}
