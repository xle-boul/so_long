/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:50:57 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/17 16:12:55 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_choose_which_hero(t_huge *data, int x, int y)
{
	if (data->swtch == 0)
		ft_image_push(data, data->hero_down, x, y);
	if (data->swtch == 1)
		ft_image_push(data, data->hero_up, x, y);
	if (data->swtch == 2)
		ft_image_push(data, data->hero_left, x, y);
	if (data->swtch == 3)
		ft_image_push(data, data->hero_right, x, y);
}

void	ft_assign_images_to_map(t_huge *data, int y, int x, char c)
{
	if (c == '1')
		ft_image_push(data, data->wall, x, y);
	else if (c == '0')
		ft_image_push(data, data->grass, x, y);
	else if (c == 'E')
		ft_image_push(data, data->exit, x, y);
	else if (c == 'C')
		ft_image_push(data, data->collectible, x, y);
	else if (c == 'B')
		ft_image_push(data, data->fly, x, y);
	else
		ft_assign_images_to_map_bonus(data, y, x, c);
}

void	ft_parse_map(t_huge *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->y_axis)
	{
		x = 0;
		while (x < data->x_axis)
		{
			ft_assign_images_to_map(data, y, x, data->map[y][x]);
			x++;
		}
		y++;
	}
}

void	ft_assign_textures_to_images(t_huge *data)
{
	data->collectible = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE, &data->img_width, &data->img_height);
	data->grass = mlx_xpm_file_to_image(data->mlx,
			GRASS, &data->img_width, &data->img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			WALL, &data->img_width, &data->img_height);
	data->hero_up = mlx_xpm_file_to_image(data->mlx,
			HERO_UP, &data->img_width, &data->img_height);
	data->hero_down = mlx_xpm_file_to_image(data->mlx,
			HERO_DOWN, &data->img_width, &data->img_height);
	data->hero_left = mlx_xpm_file_to_image(data->mlx,
			HERO_LEFT, &data->img_width, &data->img_height);
	data->hero_right = mlx_xpm_file_to_image(data->mlx,
			HERO_RIGHT, &data->img_width, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT, &data->img_width, &data->img_height);
	data->fly = mlx_xpm_file_to_image(data->mlx,
			FLY1, &data->img_width, &data->img_height);
	ft_assign_textures_to_images_bonus(data);
	data->swtch = 0;
}

void	ft_mlx_map_init(t_huge *data)
{
	data->count = -1;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			data->map_size_x, data->map_size_y + SIZE, "so_long");
	data->loop = 0;
	data->spr = 0;
	ft_assign_textures_to_images(data);
	ft_status_bar(data);
	ft_parse_map(data);
	mlx_hook(data->mlx_win, 17, 0L, &ft_free_game, data);
	mlx_key_hook(data->mlx_win, ft_movement_init, (void *)data);
	mlx_loop_hook(data->mlx, ft_sprite, (void *)data);
	mlx_loop(data->mlx);
}
