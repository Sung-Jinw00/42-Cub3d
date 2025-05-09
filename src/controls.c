/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/05/08 18:40:44 by gakarbou         ###   ########.fr       */
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
		rotation = -ROT_SPEED;
		if (ret >> 31)
			rotation = ROT_SPEED;
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

void	key_pressed_check_controls(t_game *game)
{
	int		hsp;
	int		vsp;

	hsp = game->key_infos.d_key - game->key_infos.a_key;
	vsp = game->key_infos.s_key - game->key_infos.w_key;
	game->player.mvt_speed = SPEED;
	if (hsp && vsp)
		game->player.mvt_speed /= 2;
	if (hsp >> 31)
		actualise_player_pos(game->map.map_array, &game->player, 'a');
	else if (hsp & 1)
		actualise_player_pos(game->map.map_array, &game->player, 'd');
	if (vsp >> 31)
		actualise_player_pos(game->map.map_array, &game->player, 'w');
	else if (vsp & 1)
		actualise_player_pos(game->map.map_array, &game->player, 's');
}

/* for bonus */
/* mlx_mouse_hook(map->mlx.window, mouse_hook, mlx); */
/* int	mouse_hook(int button, int x, int y, t_map *map)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_controls(button, x, y, mlx);
	return (0);
} */
