/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:17:03 by gakarbou          #+#    #+#             */
/*   Updated: 2025/05/09 16:56:45 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	draw_ceil_and_floor(int *addr, int color,
		int size_line, int len)
{
	while (len--)
	{
		*addr = color;
		addr += size_line;
	}
}

static inline void	draw_column(t_game *game, int x, t_map map_infos,
		t_raycast *ray_infos)
{
	t_img	*img;
	int		*addr;
	int		size_line;
	int		bounds[2];

	img = game->mlx.img;
	size_line = game->mlx.size_line;
	bounds[0] = ray_infos->wall_pos[0];
	bounds[1] = ray_infos->wall_pos[1];
	addr = (int *)(img->data + (x * (img->bpp >> 3)));
	draw_ceil_and_floor(addr, map_infos.c_rgb, size_line,
		bounds[0]);
	addr += size_line * (bounds[0]);
	put_texture(game, addr, ray_infos, size_line);
	addr += size_line * (bounds[1] - bounds[0]);
	draw_ceil_and_floor(addr, map_infos.f_rgb, size_line,
		WIN_HEIGHT - bounds[1]);
}

void	display_screen(t_game *game, t_opti_const consts, t_mlx mlx)
{
	t_raycast	infos;
	double		cam_coef;
	int			x;

	x = WIN_WIDTH;
	cam_coef = consts.cam_coef;
	infos.half_win_height = consts.half_height;
	while (x--)
	{
		infos.wall_dist = get_wall_dist(game->player, &infos,
				(cam_coef * x - 1), game->map.map_array);
		infos.line_height = (int)(WIN_HEIGHT / infos.wall_dist);
		infos.half_line_height = infos.line_height / 2;
		infos.wall_pos[0] = consts.half_height - infos.half_line_height;
		if (infos.wall_pos[0] >> 31)
			infos.wall_pos[0] = 0;
		infos.wall_pos[1] = infos.half_line_height + consts.half_height;
		if (infos.wall_pos[1] > WIN_HEIGHT)
			infos.wall_pos[1] = WIN_HEIGHT;
		draw_column(game, x, game->map, &infos);
	}
	mlx_put_image_to_window(mlx.init,
		mlx.window, mlx.img, 0, 0);
}
