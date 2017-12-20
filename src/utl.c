/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:49:43 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/20 18:36:32 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_offset(t_mlx *env)
{
	env->offset_x = (WIN_WIDTH - (env->xabsmax - env->xabsmin)) / 2;
	env->offset_y = (WIN_HEIGHT - (env->yabsmax - env->yabsmin)) / 2;
}
