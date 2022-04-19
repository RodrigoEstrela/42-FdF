/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:49:19 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/19 13:58:09 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	left(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->d.chgx -= 50;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	right(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->d.chgx += 50;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	up(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->d.chgy -= 50;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	down(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
	g->d.chgy += 50;
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}
