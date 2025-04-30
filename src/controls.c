/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/30 17:09:40 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed_check_camera(t_game *game)
{
	int		ret;
	double	rotation;
	double	temp;

	ret = game->key_infos.left_key - game->key_infos.right_key;
	if (ret)
	{
		rotation = 0.04 - (0.08 * (ret == 1));
		temp = game->player.direction_x;
		game->player.direction_x = temp * cos(rotation)
			- game->player.direction_y * sin(rotation);
		game->player.direction_y = temp * sin(rotation)
			+ game->player.direction_y * cos(rotation);
		temp = game->player.plane_x;
		game->player.plane_x = temp * cos(rotation)
			- game->player.plane_y * sin(rotation);
		game->player.plane_y = temp * sin(rotation)
			+ game->player.plane_y * cos(rotation);
	}
	return (ret);
}

int	key_pressed_check_controls(t_game *game)
{
	int		ret;
	int		res;

	res = 0;
	ret = game->key_infos.d_key - game->key_infos.a_key;
	if (ret)
	{
		if (ret > 0)
			ret = 'd';
		else
			ret = 'a';
		actualise_player_pos(game->map.map_array, game->player, &game->player, ret);
		res = 1;
	}
	ret = game->key_infos.s_key - game->key_infos.w_key;
	if (ret)
	{
		if (ret > 0)
			ret = 's';
		else
			ret = 'w';
		actualise_player_pos(game->map.map_array, game->player, &game->player, ret);
		res = 1;
	}
	return (res);
}

/* for bonus */
/* mlx_mouse_hook(map->mlx.window, mouse_hook, mlx); */
/* int	mouse_hook(int button, int x, int y, t_map *map)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_controls(button, x, y, mlx);
	return (0);
} */
