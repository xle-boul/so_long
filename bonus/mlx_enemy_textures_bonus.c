/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:47:09 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/16 22:34:07 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_image_push(t_huge *data, void *texture, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		texture, x * SIZE, y * SIZE);
}

void	ft_assign_images_to_map_bonus(t_huge *data, int y, int x, char c)
{
	if (c == 'P')
	{
		data->p_coord_x = x;
		data->p_coord_y = y;
		ft_choose_which_hero(data, x, y);
	}
	else if (c == 'F')
	{
		data->f_coord_x = x;
		data->f_coord_y = y;
		ft_choose_which_foe(data, x, y);
	}
	else if (c == 'S')
	{
		data->f_coord_x = x;
		data->f_coord_y = y;
		ft_choose_which_foe(data, x, y);
	}
	ft_game_over(data, 'a');
}

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
	data->vader_up_c = mlx_xpm_file_to_image(data->mlx,
			VADER_UP_C, &data->img_width, &data->img_height);
	data->vader_down_c = mlx_xpm_file_to_image(data->mlx,
			VADER_DOWN_C, &data->img_width, &data->img_height);
	data->vader_left_c = mlx_xpm_file_to_image(data->mlx,
			VADER_LEFT_C, &data->img_width, &data->img_height);
	data->vader_right_c = mlx_xpm_file_to_image(data->mlx,
			VADER_RIGHT_C, &data->img_width, &data->img_height);
	data->swtch_foe = 0;
}

void	ft_choose_which_foe(t_huge *data, int x, int y)
{
	if (data->swtch_foe == 0)
		ft_image_push(data, data->vader_down, x, y);
	if (data->swtch_foe == 1)
		ft_image_push(data, data->vader_up, x, y);
	if (data->swtch_foe == 2)
		ft_image_push(data, data->vader_left, x, y);
	if (data->swtch_foe == 3)
		ft_image_push(data, data->vader_right, x, y);
	if (data->swtch_foe == 4)
		ft_image_push(data, data->vader_down_c, x, y);
	if (data->swtch_foe == 5)
		ft_image_push(data, data->vader_up_c, x, y);
	if (data->swtch_foe == 6)
		ft_image_push(data, data->vader_left_c, x, y);
	if (data->swtch_foe == 7)
		ft_image_push(data, data->vader_right_c, x, y);
}
