/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:02:01 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/25 17:48:48 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	quit(t_map *map)
{
	mlx_loop_end(map->mlx.init);
	return (0);
}

static int	deal_key(int key, t_map *map)
{
	if (key == XK_Escape)
		quit(map);
	else if (key == XK_Left)
		;
	else if (key == XK_Right)
		;
	else if (key == XK_w)
		;
	else if (key == XK_a)
		;
	else if (key == XK_s)
		;
	else if (key == XK_d)
		;
	return (0);
}

void	mlx_hooks(t_map *map)
{
	mlx_hook(map->mlx.window, DestroyNotify, KeyReleaseMask, quit, map);
	mlx_hook(map->mlx.window, KeyPress, KeyPressMask, deal_key, map);
}

/* for bonus */
/* mlx_mouse_hook(map->mlx.window, mouse_hook, mlx); */
/* int	mouse_hook(int button, int x, int y, t_map *map)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_controls(button, x, y, mlx);
	return (0);
} */
