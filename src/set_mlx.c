/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:12:35 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/29 01:51:45 by marvin           ###   ########.fr       */
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
	mlx->img.img_id = mlx_new_image(mlx->init, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->window || !mlx->img.img_id)
	{
		mlx_destroy_image(mlx->init, mlx->img.img_id);
		mlx_destroy_window(mlx->init, mlx->window);
		ft_error("Cannot generate image or window.\n");
		return (1);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_id, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.addr)
	{
		ft_error("Cannot collect data addr.\n");
		return (1);
	}
	return (0);
}
