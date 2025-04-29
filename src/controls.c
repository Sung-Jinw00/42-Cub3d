/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/29 19:09:12 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	quit(t_game *game)
{
	mlx_loop_end(game->mlx.init);
	return (0);
}

static int	deal_key(int key, t_game *game)
{
	double	temp[2];

	if (key == XK_Escape)
		quit(game);
	else if (key == XK_Right)
	{
		temp[0] = game->player.directions[0];
		temp[1] = game->player.directions[1];
		game->player.directions[0] = temp[0] * cos(0.05) - temp[1] * sin(0.05);
		game->player.directions[1] = temp[0] * sin(0.05) + temp[1] * cos(0.05);
		temp[0] = game->player.plane[0];
		temp[1] = game->player.plane[1];
		game->player.plane[0] = temp[0] * cos(0.05) - temp[1] * sin(0.05);
		game->player.plane[1] = temp[0] * sin(0.05) + temp[1] * cos(0.05);
	}
	else if (key == XK_Left)
	{
		temp[0] = game->player.directions[0];
		temp[1] = game->player.directions[1];
		game->player.directions[0] = temp[0] * cos(-0.05) - temp[1] * sin(-0.05);
		game->player.directions[1] = temp[0] * sin(-0.05) + temp[1] * cos(-0.05);
		temp[0] = game->player.plane[0];
		temp[1] = game->player.plane[1];
		game->player.plane[0] = temp[0] * cos(-0.05) - temp[1] * sin(-0.05);
		game->player.plane[1] = temp[0] * sin(-0.05) + temp[1] * cos(-0.05);
	}
	else if (ft_strchr("wasd", key)
		&& is_valid_move(game->map.map_array, game->player, key))
		actualise_player_pos(&game->player, key);
	return (0);
}

static int	loop(t_game *game)
{
	display_screen(game);
	return (0);
}

void	init_hooks(t_game *game)
{
	mlx_hook(game->mlx.window, DestroyNotify, KeyReleaseMask, quit, game);
	mlx_hook(game->mlx.window, KeyPress, KeyPressMask, deal_key, game);
	mlx_loop_hook(game->mlx.init, loop, game);
}

/* for bonus */
/* mlx_mouse_hook(map->mlx.window, mouse_hook, mlx); */
/* int	mouse_hook(int button, int x, int y, t_map *map)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_controls(button, x, y, mlx);
	return (0);
} */
