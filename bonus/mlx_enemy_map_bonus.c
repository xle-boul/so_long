/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:47:09 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/10 01:03:05 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_assign_textures_to_images_bonus(t_huge *data)
{
	data->vader_up = mlx_xpm_file_to_image(data->mlx,
			VADER_UP, &data->img_width, &data->img_height);
	data->vader_down = mlx_xpm_file_to_image(data->mlx,
			VADER_DOWN, &data->img_width, &data->img_height);
	data->vader_left = mlx_xpm_file_to_image(data->mlx,
			VADER_LEFT, &data->img_width, &data->img_height);
	data->vader_right = mlx_xpm_file_to_image(data->mlx,
			VADER_RIGHT, &data->img_width, &data->img_height);
}

void	ft_parse_map_foe(t_huge *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < ((t_huge *)data)->y_axis)
	{
		x = 0;
		while (x < ((t_huge *)data)->x_axis)
		{
			if (((t_huge *)data)->map[y][x] == 'F')
			{
				((t_huge *)data)->f_coord_x = x;
				((t_huge *)data)->f_coord_y = y;
				ft_enemy_movement_init(data, 5);
			}
			x++;
		}
		y++;
	}
}
