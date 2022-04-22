/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:24 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/22 18:27:14 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	blue(t_winint *g)
{
	g->img.colorcode = 0x000000FF;
	draw_img(g);
}

static void	green(t_winint *g)
{
	g->img.colorcode = 0x0000FF00;
	draw_img(g);
}

static void	yellow(t_winint *g)
{
	g->img.colorcode = 0x00FFFF00;
	draw_img(g);
}

static void	red(t_winint *g)
{
	g->img.colorcode = 0x00FF0000;
	draw_img(g);
}

void	colors(int key, t_winint *g)
{
	clean_slate(g);
	if (key == 0)
		blue(g);
	else if (key == 1)
		green(g);
	else if (key == 2)
		yellow(g);
	else if (key == 3)
		red(g);
}
