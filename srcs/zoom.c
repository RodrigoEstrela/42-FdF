/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:12:55 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/19 16:39:33 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	zoom_in(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	if (g->bs < 30)
		g->bs *= 1.5;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

static void	zoom_out(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	if (g->bs > 1)
		g->bs /= 1.5;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	zoom(int key, t_winint *g)
{
	if (key == 6)
		zoom_in(g);
	else if (key == 7)
		zoom_out(g);
}
