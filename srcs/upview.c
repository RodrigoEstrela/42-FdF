/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upview.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:19:26 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/21 13:37:14 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	up_view(t_winint *g)
{
	int	*cen;

	cen = (int [4]){-1, 0, 100, 100};
	clean_slate(g);
	while (++cen[0] <= g->d.l)
	{
		while (cen[1] < (g->d.c - 1) * g->bs)
			my_mlx_pixel_put(&g->img, cen[2] + cen[1]++, cen[3], g->img.color);
		cen[1] = 0;
		cen[3] = 100 + (cen[0] * g->bs);
	}
	cen[0] = -1;
	cen[1] = 0;
	cen[3] = 100;
	while (++cen[0] <= g->d.c)
	{
		while (cen[1] < (g->d.l -1) * g->bs)
			my_mlx_pixel_put(&g->img, cen[2], cen[3] + cen[1]++, g->img.color);
		cen[1] = 0;
		cen[2] = 100 + (cen[0] * g->bs);
	}
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}
