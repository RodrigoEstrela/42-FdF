/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer_constructor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:57:18 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/13 17:03:27 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	line_drawer(t_dimen dim, t_guhuza **m, t_data img)
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
			super_liner(pts, img);
			b++;
		}
		b = 0;
		a++;
	}
}

void	column_drawer(t_dimen dim, t_guhuza **m, t_data img)
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
