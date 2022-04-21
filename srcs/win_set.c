/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:13:52 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/21 17:57:11 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < W && y >= 0 && y < H)
	{
		dst = data->addr + (y * data->len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

t_winint	graf_init(void)
{
	t_winint	g;

	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, W, H, "Fil de Fer");
	g.img.img = mlx_new_image(g.mlx, W, H);
	g.img.addr = mlx_get_data_addr(g.img.img, &g.img.bpp, &g.img.len, &g.img.e);
	return (g);
}

void	draw_img(t_winint *g)
{
	g->m = calc_mesh(g->d, g->bs, g->inp, g->m);
	y_updater(g->d, g->m, g->bs);
	fil_de_fer(g->d, g->m, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	clean_slate(t_winint *g)
{
	ft_bzero(g->img.addr, H * W * (g->img.bpp / 8));
}

void	reset_view(int key, t_winint *g)
{
	if (key == 34)
	{
		clean_slate(g);
		draw_img(g);
	}
}
