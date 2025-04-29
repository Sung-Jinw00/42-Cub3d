/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:21:23 by gakarbou          #+#    #+#             */
/*   Updated: 2025/04/29 16:34:43 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*copy_line(int j, void *img, int len)
{
	int		*dest;
	int		i;

	dest = malloc(sizeof(int) * (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = get_pixel_color(img, i, j);
	dest[i] = -1;
	return (dest);
}

int	**store_image(char *pathname, void *mlx_ptr)
{
	int		**frame_buffer;
	t_img	*mlx_img;
	int		file_dimensions[2];
	int		j;

	mlx_img = mlx_xpm_file_to_image(mlx_ptr, pathname, &file_dimensions[0],
			&file_dimensions[1]);
	frame_buffer = malloc(sizeof(int *) * (file_dimensions[1] + 1));
	if (!frame_buffer)
	{
		mlx_destroy_image(mlx_ptr, mlx_img);
		return (NULL);
	}
	j = -1;
	while (++j < file_dimensions[1])
		frame_buffer[j] = copy_line(j, mlx_img, file_dimensions[0]);
	mlx_destroy_image(mlx_ptr, mlx_img);
	frame_buffer[j] = NULL;
	return (frame_buffer);
}
