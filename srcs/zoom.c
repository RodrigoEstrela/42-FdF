/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:12:55 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/21 17:53:10 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	zoom_in(t_winint *g)
{
	clean_slate(g);
	if (g->bs == 1)
		g->bs += 1;
	else if (g->bs == 2)
		g->bs += 1;
	else if (g->bs < 90 && g->bs > 2)
		g->bs += 3;
	draw_img(g);
}

static void	zoom_out(t_winint *g)
{
	clean_slate(g);
	if (g->bs > 3)
		g->bs -= 3;
	else if (g->bs == 3)
		g->bs -= 1;
	else if (g->bs == 2)
		g->bs -= 1;
	draw_img(g);
}

void	zoom(int key, t_winint *g)
{
	if (key == 6)
		zoom_in(g);
	else if (key == 7)
		zoom_out(g);
}
