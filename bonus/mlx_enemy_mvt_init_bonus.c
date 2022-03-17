/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_mvt_init_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:29:41 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/16 22:23:46 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_random_number_generator(void)
{
	int		i;
	time_t	seconds;

	time(&seconds);
	i = (rand() + seconds) % 4;
	return (i);
}

void	ft_enemy_movement_init(t_huge *data, int sec)
{
	int			mvt;
	static int	checker;

	mvt = ft_random_number_generator();
	if (sec != checker)
	{
		if (mvt == 0)
			ft_enemy_move_up(data);
		else if (mvt == 1)
			ft_enemy_move_down(data);
		else if (mvt == 2)
			ft_enemy_move_left(data);
		else if (mvt == 3)
			ft_enemy_move_right(data);
	}
	checker = sec;
}
