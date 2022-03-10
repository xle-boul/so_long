/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:50:57 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/08 22:10:31 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_choose_which_hero(t_huge *data, int x, int y)
{
	if (data->swtch == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->hero_down, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	if (data->swtch == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->hero_up, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	if (data->swtch == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->hero_left, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	if (data->swtch == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->hero_right, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

void	ft_assign_images_to_map(t_huge *data, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->wall, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->grass, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->exit, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->collectible, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	else if (c == 'P')
	{
		ft_choose_which_hero(data, x, y);
		data->p_coord_x = x;
		data->p_coord_y = y;
	}
}

void	ft_parse_map(t_huge *data)
{
	int	y;
	int	x;

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
	data->swtch = 0;
}

void	*ft_hook(void *data)
{
	mlx_hook(((t_huge *)data)->mlx_win, 17, 0L, &ft_free_game, (t_huge *)data);
	mlx_hook(((t_huge *)data)->mlx_win, 2, 1L << 0, &ft_movement_init, (t_huge *)data);
	return (0);
}
void	ft_mlx_map_init(t_huge *data)
{
	pthread_t	tid;
	
	data->count = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			data->map_size_x, data->map_size_y, "so_long");
	ft_assign_textures_to_images(data);
	ft_assign_textures_to_images_bonus(data);
	ft_parse_map(data);
	ft_parse_map_foe(data);
	pthread_create(&tid, NULL, &ft_hook, (void *)data);
	pthread_join(tid, NULL);
	mlx_loop(data->mlx);
}