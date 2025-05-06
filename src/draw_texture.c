/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:36:53 by gakarbou          #+#    #+#             */
/*   Updated: 2025/05/06 06:00:37 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline int	get_tex_color(t_texture tex, int y, int x)
{
	return (*(int *)(tex.data + (y * tex.size_line + x)));
}

static t_texture	get_texture(t_game *game, t_raycast *infos, double *wall_x)
{
	if (!infos->side)
	{
		*wall_x = game->player.y + infos->wall_dist * infos->ray_dir[1];
		if (infos->ray_dir[0] < 0)
			return (game->map.tex_list[3]);
		return (game->map.tex_list[2]);
	}
	*wall_x = game->player.x + infos->wall_dist * infos->ray_dir[0];
	if (infos->ray_dir[1] < 0)
		return (game->map.tex_list[1]);
	return (game->map.tex_list[0]);
}

static void	draw_texture(int *addr, int size_line,
		t_texture tex, t_raycast *infos)
{
	void	*data;
	double	tex_pos;
	double	step;
	int		tex_x;
	int		y;

	step = 1.0 * tex.height / infos->line_height;
	tex_pos = (infos->wall_pos[0] - WIN_HEIGHT / 2 + infos->half_line_height)
		* step;
	y = infos->wall_pos[1] - infos->wall_pos[0];
	tex_x = infos->texture_x;
	data = tex.data;
	while (y--)
	{
		*addr = *(int *)(data + ((int)tex_pos & tex.tex_endian)
				* tex.size_line + tex_x);
		tex_pos += step;
		addr += size_line;
	}
}

void	put_texture(t_game *game, int *addr, int size_line, t_raycast *infos)
{
	int			tex_width;
	int			tex_x;
	double		wall_x;
	t_texture	tex;

	tex = get_texture(game, infos, &wall_x);
	wall_x -= (int)wall_x;
	tex_width = tex.width;
	tex_x = ((wall_x - (int)wall_x) * tex.d_width);
	if (!infos->side && (infos->ray_dir[0] > 0))
		tex_x = tex_width - tex_x - 1;
	else if (infos->side && (infos->ray_dir[1] < 0))
		tex_x = tex_width - tex_x - 1;
	infos->texture_x = tex_x * tex.fake_bpp;
	draw_texture(addr, size_line, tex, infos);
}
