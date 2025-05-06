/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/05/06 12:35:25 by gakarbou         ###   ########.fr       */
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

static void	update_movement_speed(t_keyboard_control infos, double *speed)
{
	int		hsp;
	int		vsp;

	hsp = infos.d_key - infos.a_key;
	vsp = infos.s_key - infos.w_key;
	if (hsp && vsp)
		*speed = SPEED / 2;
	else
		*speed = SPEED;
}

void	key_pressed_check_controls(t_game *game)
{
	int		ret;

	update_movement_speed(game->key_infos, &game->player.mvt_speed);
	ret = game->key_infos.d_key - game->key_infos.a_key;
	if (ret)
	{
		if (ret > 0)
			ret = 'd';
		else
			ret = 'a';
		actualise_player_pos(game->map.map_array, &game->player, ret);
	}
	ret = game->key_infos.s_key - game->key_infos.w_key;
	if (ret)
	{
		if (ret > 0)
			ret = 's';
		else
			ret = 'w';
		actualise_player_pos(game->map.map_array, &game->player, ret);
	}
}

/* for bonus */
/* mlx_mouse_hook(map->mlx.window, mouse_hook, mlx); */
/* int	mouse_hook(int button, int x, int y, t_map *map)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_controls(button, x, y, mlx);
	return (0);
} */
