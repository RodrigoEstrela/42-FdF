/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:21:58 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/13 14:53:01 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

float	s(float x1, int y1, int x2, int y2)
{
	float	ret;

	ret = (y2 - y1) / (x2 - x1);
	return (ret);
}

void	upper_liner(int *p, int *pl, t_data img)
{
	my_mlx_pixel_put(&img, ++pl[0], --pl[1], GREEN);
	while (pl[0] != p[2] || pl[1] != p[3])
	{
		if (s((F)p[0], p[1], pl[0], pl[1]) <= s((F)p[0], p[1], p[2], p[3]))
			my_mlx_pixel_put(&img, ++pl[0], pl[1], GREEN);
		else
			my_mlx_pixel_put(&img, pl[0], --pl[1], GREEN);
	}
}

void	downer_liner(int *p, int *pl, t_data img)
{
	my_mlx_pixel_put(&img, ++pl[0], ++pl[1], GREEN);
	while (pl[0] != p[2] || pl[1] != p[3])
	{
		if (s((F)p[0], p[1], pl[0], pl[1]) >= s((F)p[0], p[1], p[2], p[3]))
			my_mlx_pixel_put(&img, ++pl[0], pl[1], GREEN);
		else
			my_mlx_pixel_put(&img, pl[0], ++pl[1], GREEN);
	}
}

void	super_liner(int *p, t_data img)
{
	int	*pl;

	pl = (int [2]){(F)p[0], p[1]};
	if (s((F)p[0], p[1], p[2], p[3]) < 0.000)
		upper_liner(p, pl, img);
	else if (s((F)p[0], p[1], p[2], p[3]) > 0.000)
		downer_liner(p, pl, img);
	else
		while (pl[0] != p[2] || pl[1] != p[3])
			my_mlx_pixel_put(&img, ++pl[0], pl[1], GREEN);
}
