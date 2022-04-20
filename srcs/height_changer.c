/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_changer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:14:45 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/20 15:13:13 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	height_downer(t_winint *g)
{
	clean_slate(g);
	g->d.chg[2] -= 1;
	draw_img(g);
}

static void	height_upper(t_winint *g)
{
	clean_slate(g);
	g->d.chg[2] += 1;
	draw_img(g);
}

void	height_changer(int key, t_winint *g)
{
	if (key == 43)
		height_downer(g);
	else if (key == 47)
		height_upper(g);
}
