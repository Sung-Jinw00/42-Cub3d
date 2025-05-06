/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:17:03 by gakarbou          #+#    #+#             */
/*   Updated: 2025/05/06 05:40:16 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	draw_ceil_and_floor(int *addr, int color,
		int size_line, int len)
{
	int			i;

	i = 0;
	while (i++ < len)
	{
		*addr = color;
		addr += size_line;
	}
}

static void	draw_column(t_game *game, int x, t_map map_infos,
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
	draw_ceil_and_floor(addr, map_infos.c_rgb, size_line, bounds[0]);
	addr += size_line * (bounds[0]);
	put_texture(game, addr, size_line, ray_infos);
	addr += size_line * (bounds[1] - bounds[0]);
	draw_ceil_and_floor(addr, map_infos.f_rgb, size_line,
		WIN_HEIGHT - bounds[1]);
}

void	display_screen(t_game *game, t_opti_const consts)
{
	t_raycast	infos;
	double		cam_coef;
	int			x;

	cam_coef = 2 / consts.float_width;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		infos.wall_dist = get_wall_dist(game, &infos,
				(cam_coef * x - 1), game->map.map_array);
		infos.line_height = (WIN_HEIGHT / infos.wall_dist);
		infos.half_line_height = infos.line_height / 2;
		infos.wall_pos[0] = -infos.half_line_height
			+ consts.half_height;
		if (infos.wall_pos[0] >> 31)
			infos.wall_pos[0] = 0;
		infos.wall_pos[1] = infos.half_line_height + consts.half_height;
		if (infos.wall_pos[1] > WIN_HEIGHT)
			infos.wall_pos[1] = WIN_HEIGHT;
		draw_column(game, x, game->map, &infos);
	}
	mlx_put_image_to_window(game->mlx.init,
		game->mlx.window, game->mlx.img, 0, 0);
}
