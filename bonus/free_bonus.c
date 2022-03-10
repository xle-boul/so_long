/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:56:05 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/09 21:15:54 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// Speaks for itself

void	ft_free_list(t_map *head)
{
	t_map	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head->next;
		free (head->line);
		free (head);
		head = tmp;
	}
	head = NULL;
}

// This one too

void	ft_free_map(t_huge *data)
{
	int	i;

	i = data->y_axis - 1;
	while (i >= 0)
	{
		free (data->map[i]);
		i--;
	}
	free (data->map);
}

int	ft_free_game(t_huge *data)
{
	if (data->mlx)
	{
		mlx_destroy_image(data->mlx, data->collectible);
		mlx_destroy_image(data->mlx, data->hero_down);
		mlx_destroy_image(data->mlx, data->hero_up);
		mlx_destroy_image(data->mlx, data->hero_left);
		mlx_destroy_image(data->mlx, data->hero_right);
		mlx_destroy_image(data->mlx, data->vader_down);
		mlx_destroy_image(data->mlx, data->vader_up);
		mlx_destroy_image(data->mlx, data->vader_left);
		mlx_destroy_image(data->mlx, data->vader_right);
		mlx_destroy_image(data->mlx, data->exit);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->grass);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_map(data);
	exit(EXIT_SUCCESS);
}
