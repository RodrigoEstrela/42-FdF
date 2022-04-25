/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:22:38 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/25 12:12:55 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	main(int ac, char **av)
{
	int			counter;
	t_winint	g;

	if (error_check(ac, av[1]) == 0)
		return (0);
	g = graf_init();
	g.inp = av[1];
	counter = 0;
	g.d = dim_formater(g.inp);
	if (g.d.c == -1)
		return (0);
	g.bs = bargaksetra(g.d.c, g.d.l);
	g.m = malltrix(g.m, &g);
	g.d.chg = (int [3]){0, 0, 1};
	g.img.color = 0xFFFFFF;
	g.m = calc_mesh(g.d, g.bs, g.inp, g.m);
	y_updater(g.d, g.m, g.bs);
	fil_de_fer(g.d, g.m, g.img);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.img.img, 0, 0);
	graph_actions(g);
	mlx_loop(g.mlx);
	free(g.m);
}
