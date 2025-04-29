/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:12:35 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/29 17:23:32 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_mlx(t_mlx *mlx, char *win_title)
{
	mlx->init = mlx_init();
	if (!mlx->init)
	{
		ft_error("Cannot initiate mlx.\n");
		return (1);
	}
	mlx->window = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, win_title);
	mlx->img = NULL;
	if (!mlx->window)
	{
		mlx_destroy_window(mlx->init, mlx->window);
		ft_error("Cannot generate image or window.\n");
		return (1);
	}
	return (0);
}
