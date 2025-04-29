/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/29 16:11:01 by locagnio         ###   ########.fr       */
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
	if (key == XK_Escape)
		quit(game);
	else if (key == XK_Left)
		;
	else if (key == XK_Right)
		;
	else if (ft_strchr("wasd", key)
		&& is_valid_move(game->map.map_array, game->player, key))
		actualise_player_pos(&game->player, key);
	return (0);
}

static int	loop(t_game *game)
{
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
