/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:16:46 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/19 14:27:23 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	key_action(int key, t_winint *g)
{
	if (key == 53)
		exit(0);
	else if (key == 123)
		left(g);
	else if (key == 124)
		right(g);
	else if (key == 125)
		down(g);
	else if (key == 126)
		up(g);
	else if (key == 11)
		g->img.color = 0x000000FF;
	return (0);
}

static int	on_destroy_win(void)
{
	exit(0);
	return (0);
}

void	graph_actions(t_winint g)
{
	mlx_hook(g.mlx_win, 2, 1L << 0, key_action, &g);
	mlx_hook(g.mlx_win, 17, 1L << 0, on_destroy_win, &g);
}
