/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer_constructor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:57:18 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/22 18:35:53 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	color_cmp(int a, int b)
{
	if (a == b && a != -1)
		return (1);
	return (0);
}

static void	line_drawer(t_dimen dim, t_guhuza **m, t_data img)
{
	int	a;
	int	b;
	int	*pts;

	a = 0;
	b = 0;
	while (a < dim.l)
	{
		while (b < dim.c - 1)
		{
			pts = (int [8]){m[a][b].x, m[a][b].y, m[a][b + 1].x, m[a][b + 1].y};
			if (color_cmp(m[a][b].color, m[a][b + 1].color))
				img.color = m[a][b].color;
			else
				img.color = img.colorcode;
			super_liner(pts, img);
			b++;
		}
		b = 0;
		a++;
	}
}

static void	column_drawer(t_dimen dim, t_guhuza **m, t_data img)
{
	int	a;
	int	b;
	int	*pts;

	a = 0;
	b = 0;
	while (a < dim.l - 1)
	{
		while (b < dim.c)
		{
			pts = (int [8]){m[a][b].x, m[a][b].y, m[a + 1][b].x, m[a + 1][b].y};
			if (color_cmp(m[a][b].color, m[a + 1][b].color))
				img.color = m[a][b].color;
			else
				img.color = img.colorcode;
			super_liner(pts, img);
			b++;
		}
		b = 0;
		a++;
	}
}

void	fil_de_fer(t_dimen dim, t_guhuza **m, t_data img)
{
	line_drawer(dim, m, img);
	column_drawer(dim, m, img);
}
