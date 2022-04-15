/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:16:46 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/15 17:43:43 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	close_win(int key, t_winint g)
{
	if (key == 53)
	{
		mlx_destroy_window(g.mlx, g.mlx_win);
		exit(0);
	}
	return (0);
}

static int	on_destroy_win(void)
{
	exit(0);
	return (0);
}

void	graph_actions(t_winint g)
{
	mlx_hook(g.mlx_win, 2, 1L << 0, close_win, &g);
	mlx_hook(g.mlx_win, 17, 1L << 0, on_destroy_win, &g);
}
