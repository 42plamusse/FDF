/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:06:16 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/20 18:50:34 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_env(t_mlx *env)
{
	t_img	ctx;

	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->data = (int*)mlx_get_data_addr(env->img, &ctx.bpp, &ctx.sl,
		&ctx.endian);
}

static void	handle_coord(t_mlx *env, t_list *lst)
{
	get_max_coord(env, lst);
	get_iso_dim(env, lst);
	env->gutter_widthx = (WIN_WIDTH - 100) / (env->isox_max - env->isox_min);
	env->gutter_widthy = (WIN_HEIGHT - 50) / (env->isoy_max - env->isoy_min);
	to_pixel(lst, env);
	get_absolute_dimensions(env, lst);
	get_offset(env);
	apply_offset(env, lst);
}

static void	display(t_mlx *env)
{
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx_put_image_to_window(env->data, env->win, env->img, 0, 0);
}

int			main(int argc, char **argv)
{
	t_mlx	env;
	int		fd;
	t_list	*lst;

	lst = NULL;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_printf("usage: %s [map]\n", argv[0]);
		return (-1);
	}
	if (!map_parser(&lst, fd) || !lst)
	{
		ft_printf("error: parsing or malloc failed\n");
		ft_lstdel(&lst, &ft_lst_memclr);
		return (-1);
	}
	init_env(&env);
	if (ft_lstlen(lst) != 1)
		handle_coord(&env, lst);
	draw_surface(lst, 0, 0, &env);
	display(&env);
	mlx_key_hook(env.win, quit, (void*)lst);
	ft_lstdel(&lst, &ft_lst_memclr);
	mlx_loop(env.mlx);
	return (0);
}
