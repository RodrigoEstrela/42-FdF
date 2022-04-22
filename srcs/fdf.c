/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:22:38 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/22 12:56:48 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	y_updater(t_dimen dim, t_guhuza **matriz, float bargak_setra)
{
	int	s;
	int	t;

	s = 0;
	t = 0;
	while (s < dim.l)
	{
		while (t < dim.c)
		{
			matriz[s][t].y -= matriz[s][t].z * bargak_setra;
			t++;
		}
		t = 0;
		s++;
	}
}

t_dimen	dim_formater(char *map)
{
	t_dimen	dim;
	int		fd;
	char	*line;
	int		checker;

	dim.c = 0;
	dim.l = 0;
	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	checker = valuescount(line);
	while (line)
	{
		dim.c = valuescount(line);
		if (dim.c != checker)
		{
			dim.c = -1;
			ft_printf("\n\e[0;31mWRONG LENGTH ON MAP!\n\n");
			return (dim);
		}
		dim.l++;
		free(line);
		line = get_next_line(fd);
	}	
	close(fd);
	return (dim);
}

t_guhuza	**calc_mesh(t_dimen d, float bs, char *str, t_guhuza **m)
{
	char		*mr;
	int			*ar;
	char		**pp;

	ar = (int [7]){-1, d.l, open(str, O_RDWR), W / 2, H / 2, W / 2, H / 2};
	while (--ar[1] >= 0)
	{
		mr = get_next_line(ar[2]);
		pp = ft_split(mr, 32);
		while (++ar[0] < d.c)
		{
			m[ar[1]][ar[0]].x = ar[3] + d.chg[0];
			m[ar[1]][ar[0]].y = ar[4] + d.chg[1];
			m[d.l - ar[1] - 1][ar[0]].z = ft_atoi(pp[ar[0]]) * d.chg[2];
			ar[3] += (bs * 2);
			ar[4] -= (bs);
		}
		ar[5] -= (bs * 2);
		ar[6] -= (bs);
		ar[3] = ar[5];
		ar[4] = ar[6];
		ar[0] = -1;
	}
	return (m);
}

int	main(int ac, char **av)
{
	int			counter;
	t_winint	g;

	if (error_check(ac, av[1]) == 0)
		return (0);
	g = graf_init();
	g.inp = ft_calloc(ft_strlen(av[1] + 1), sizeof(char *));
	g.inp = ft_strdup((const char *)av[1]);
	counter = 0;
	g.d = dim_formater(g.inp);
	if (g.d.c == -1)
		return (0);
	g.bs = bargaksetra(g.d.c, g.d.l);
	g.m = malloc(sizeof(t_guhuza *) * g.d.l);
	while (counter < g.d.l)
		g.m[counter++] = malloc(sizeof(t_guhuza) * g.d.c);
	g.d.chg = (int [3]){0, 0, 1};
	g.img.color = 0x0000FF00;
	g.m = calc_mesh(g.d, g.bs, g.inp, g.m);
	y_updater(g.d, g.m, g.bs);
	fil_de_fer(g.d, g.m, g.img);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.img.img, 0, 0);
	graph_actions(g);
	mlx_loop(g.mlx);
}
