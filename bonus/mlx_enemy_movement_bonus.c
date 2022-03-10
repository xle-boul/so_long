/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_movement_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:42:54 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/09 23:52:03 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_enemy_move_up(t_huge *data, int mvt)
{
	if (data->map[data->f_coord_y - 1][data->f_coord_x] == '0')
	{
		data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y - 1][data->f_coord_x + 1] = 'F';
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->vader_up, data->f_coord_x * TEXTURE_SIZE,
					(data->f_coord_y - 1) * TEXTURE_SIZE);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->grass, data->f_coord_x * TEXTURE_SIZE,
					(data->f_coord_y) * TEXTURE_SIZE);
		data->f_coord_y -= 1;
		sleep(1);
		ft_enemy_movement_init(data, 5);
	}
	else
		ft_enemy_movement_init(data, mvt);
}

void	ft_enemy_move_down(t_huge *data, int mvt)
{
	if (data->map[data->f_coord_y + 1][data->f_coord_x] == '0')
	{
		data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y + 1][data->f_coord_x] = 'F';
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->vader_down, data->f_coord_x * TEXTURE_SIZE,
					(data->f_coord_y + 1) * TEXTURE_SIZE);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->grass, data->f_coord_x * TEXTURE_SIZE,
					(data->f_coord_y) * TEXTURE_SIZE);
		data->f_coord_y += 1;
		sleep(1);
		ft_enemy_movement_init(data, 5);
	}
	else
		ft_enemy_movement_init(data, mvt);
}

void	ft_enemy_move_left(t_huge *data, int mvt)
{
	if (data->map[data->f_coord_y][data->f_coord_x - 1] == '0')
	{
		data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y][data->f_coord_x - 1] = 'F';
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->vader_left, (data->f_coord_x - 1) * TEXTURE_SIZE,
					(data->f_coord_y) * TEXTURE_SIZE);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->grass, data->f_coord_x * TEXTURE_SIZE,
					(data->f_coord_y) * TEXTURE_SIZE);
		data->f_coord_x -= 1;
		sleep(1);
		ft_enemy_movement_init(data, 5);
	}
	else
		ft_enemy_movement_init(data, mvt);
}

void	ft_enemy_move_right(t_huge *data, int mvt)
{
	if (data->map[data->f_coord_y][data->f_coord_x + 1] == '0')
	{
		data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y][data->f_coord_x + 1] = 'F';
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->vader_right, (data->f_coord_x + 1) * TEXTURE_SIZE,
					(data->f_coord_y) * TEXTURE_SIZE);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->grass, data->f_coord_x * TEXTURE_SIZE,
					(data->f_coord_y) * TEXTURE_SIZE);
		data->f_coord_x += 1;
		sleep(1);
		ft_enemy_movement_init(data, 5);
	}
	else
		ft_enemy_movement_init(data, mvt);
}

