/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:41:59 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/17 16:25:18 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_string_to_map(t_huge *data)
{
	char	*steps;
	char	*coll;

	steps = ft_itoa(data->count);
	coll = ft_itoa(data->c);
	ft_status_bar(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->st,
		SIZE, data->map_size_y);
	mlx_string_put(data->mlx, data->mlx_win, SIZE + 10,
		data->map_size_y + SIZE / 2 + 5, 0xffffff, steps);
	mlx_string_put(data->mlx, data->mlx_win, 3 * SIZE + 10,
		data->map_size_y + SIZE / 2 + 5, 0xffffff, coll);
	free(steps);
	free(coll);
}

void	ft_status_bar(t_huge *data)
{
	int	i;
	int	size;
	static int	check = 0;

	if (check != 0)
		ft_keep_freeing_game(data);
	i = 0;
	size = data->map_size_x;
	data->st = mlx_xpm_file_to_image(data->mlx,
			STATUS, &data->img_width, &data->img_height);
	data->stf = mlx_xpm_file_to_image(data->mlx,
			STATUS_FOOT, &data->img_width, &data->img_height);
	data->stc = mlx_xpm_file_to_image(data->mlx,
			STATUS_COIN, &data->img_width, &data->img_height);
	while (i < size)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->st, i, data->map_size_y);
		i += 32;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->stf, 0, data->map_size_y);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->stc, 2 * SIZE, data->map_size_y);
	check++;
}