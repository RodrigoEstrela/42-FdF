/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:13:52 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/14 12:55:53 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
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
