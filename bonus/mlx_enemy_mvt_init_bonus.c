/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_mvt_init_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:29:41 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/10 00:33:59 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_random_number_generator(int check)
{
	int	i;

	i = 0;
	srand(time(0));
	i = rand() %4;
	if (i == check)
	{
		if (i != 3)
			i++;
		else if (i == 3)
			i = 0;
	}
	ft_printf("%d\n", i);
	return (i);
}

void	ft_enemy_movement_init(t_huge *data, int check)
{
	int	mvt;

	mvt = ft_random_number_generator(check);
	if (mvt == 0)
		ft_enemy_move_up(data, mvt);
	if (mvt == 1)
		ft_enemy_move_down(data, mvt);
	if (mvt == 2)
		ft_enemy_move_left(data, mvt);
	if (mvt == 3)
		ft_enemy_move_right(data, mvt);
}