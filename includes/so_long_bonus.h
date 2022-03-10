/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:19:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/10 00:57:20 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <time.h>
# include <pthread.h>
# include "so_long.h"

# define VADER_UP "textures/vader/vader_back.xpm"
# define VADER_DOWN "textures/vader/vader_front.xpm"
# define VADER_LEFT "textures/vader/vader_left.xpm"
# define VADER_RIGHT "textures/vader/vader_right.xpm"

# define MAP_CHARS_BONUS "01ECPF"

void	ft_assign_textures_to_images_bonus(t_huge *data);
void	ft_enemy_move_up(t_huge *data, int mvt);
void	ft_enemy_move_down(t_huge *data, int mvt);
void	ft_enemy_move_left(t_huge *data, int mvt);
void	ft_enemy_move_right(t_huge *data, int mvt);
void	ft_parse_map_foe(t_huge *data);
void	ft_enemy_movement_init(t_huge *data, int mvt);

#endif