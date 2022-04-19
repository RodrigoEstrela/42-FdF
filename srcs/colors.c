/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:24 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/19 15:49:52 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	blue(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->img.color = 0x000000FF;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

static void	green(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->img.color = 0x0000FF00;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

static void	yellow(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->img.color = 0x00FFFF00;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

static void	red(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->img.color = 0x00FF0000;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	colors(int key, t_winint *g)
{
	if (key == 0)
		blue(g);
	else if (key == 1)
		green(g);
	else if (key == 2)
		yellow(g);
	else if (key == 3)
		red(g);
}
