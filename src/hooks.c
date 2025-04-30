/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:51:28 by gakarbou          #+#    #+#             */
/*   Updated: 2025/04/30 17:09:18 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	quit(t_game *game)
{
	mlx_loop_end(game->mlx.init);
	return (0);
}

static int	pressed_key(int key, t_game *game)
{
	if (key == XK_Escape)
		quit(game);
	else if (key == 'w')
		game->key_infos.w_key = 1;
	else if (key == 'a')
		game->key_infos.a_key = 1;
	else if (key == 's')
		game->key_infos.s_key = 1;
	else if (key == 'd')
		game->key_infos.d_key = 1;
	else if (key == XK_Left)
		game->key_infos.left_key = 1;
	else if (key == XK_Right)
		game->key_infos.right_key = 1;
	return (0);
}

static int	release_key(int key, t_game *game)
{
	if (key == 'w')
		game->key_infos.w_key = 0;
	else if (key == 'a')
		game->key_infos.a_key = 0;
	else if (key == 's')
		game->key_infos.s_key = 0;
	else if (key == 'd')
		game->key_infos.d_key = 0;
	else if (key == XK_Left)
		game->key_infos.left_key = 0;
	else if (key == XK_Right)
		game->key_infos.right_key = 0;
	return (0);
}

static int	loop(t_game *game)
{
	int		ret;

	ret = key_pressed_check_controls(game);
	ret += key_pressed_check_camera(game);
	display_screen(game);
	return (0);
}

void	init_hooks(t_game *game)
{
	game->key_infos = (t_keyboard_control){0, 0, 0, 0, 0, 0};
	mlx_hook(game->mlx.window, DestroyNotify, KeyReleaseMask, quit, game);
	mlx_hook(game->mlx.window, KeyPress, KeyPressMask, pressed_key, game);
	mlx_hook(game->mlx.window, KeyRelease, KeyReleaseMask, release_key, game);
	mlx_loop_hook(game->mlx.init, loop, game);
}
