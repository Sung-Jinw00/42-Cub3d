/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:18:14 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 20:50:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static inline char return_token_map(t_map map, int pos[2],
	int line_b[2], int col_b[3])
{
	int line;
	int col;
	double arr_map_ratio;

	arr_map_ratio = (double)line_b[0] / (double)map.w_map;
	line = (int)((pos[0] - line_b[0]) / arr_map_ratio);
	arr_map_ratio = (double)col_b[0] / (double)map.h_map;
	col = (int)((pos[1] - col_b[0]) / arr_map_ratio);
	return (map.map_array[line][col]);
}

static inline void	put_minimap_pixels(t_game game, int line_b[2],
	int col_b[3], double player_pos[2])
{
	int		x;
	int		y;
	char	box_token;

	x = line_b[0];
	while (x < line_b[1])
	{
		y = col_b[0];
		while (y < col_b[1])
		{
			box_token = return_token_map(game.map, (int[2]){x, y}, line_b,
				col_b);
			if ((int)player_pos[0] == x && (int)player_pos[1] == y)
				mlx_pixel_put(game.mlx.init, game.mlx.window, x, y, 0x00FF00);
			else if (box_token == '1' || box_token == ' ' || x == line_b[0]
				|| x == line_b[1] - 1 || y == col_b[0] || y == col_b[1] - 1)
				mlx_pixel_put(game.mlx.init, game.mlx.window, x, y, 0x000000);
			else
				mlx_pixel_put(game.mlx.init, game.mlx.window, x, y, 0x808080);
			y++;
		}
		x++;
	}
}

void	display_minimap(t_game game)
{
	int		line_borders[2];
	int		col_borders[3];
	double	arr_map_ratio;
	double	player_pos[2];

	line_borders[0] = WIN_HEIGHT / 20;
	line_borders[1] = line_borders[0] * 2;
	col_borders[2] = WIN_WIDTH / 20;
	col_borders[1] = WIN_WIDTH - col_borders[2];
	col_borders[0] = col_borders[1] - col_borders[2];
	arr_map_ratio = (double)line_borders[0] / (double)game.map.w_map;
	player_pos[0] = (line_borders[0] + game.player.x * arr_map_ratio);
	arr_map_ratio = (double)col_borders[0] / (double)game.map.h_map;
	player_pos[1] = (col_borders[0] + game.player.y * arr_map_ratio);
	put_minimap_pixels(game, line_borders, col_borders, player_pos);
	mlx_put_image_to_window(game.mlx.init, game.mlx.window, game.mlx.img, 0, 0);
}
