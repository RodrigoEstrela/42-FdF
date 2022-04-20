/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:49:19 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/20 15:15:42 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	left(t_winint *g)
{
	clean_slate(g);
	g->d.chg[0] -= 37;
	draw_img(g);
}

static void	right(t_winint *g)
{
	clean_slate(g);
	g->d.chg[0] += 37;
	draw_img(g);
}

static void	up(t_winint *g)
{
	clean_slate(g);
	g->d.chg[1] -= 37;
	draw_img(g);
}

static void	down(t_winint *g)
{
	clean_slate(g);
	g->d.chg[1] += 37;
	draw_img(g);
}

void	directions(int key, t_winint *g)
{
	if (key == 123)
		left(g);
	else if (key == 124)
		right(g);
	else if (key == 125)
		down(g);
	else if (key == 126)
		up(g);
}
