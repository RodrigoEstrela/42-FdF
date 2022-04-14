/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:22:38 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/14 18:23:38 by rdas-nev         ###   ########.fr       */
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
			matriz[s][t].y -= matriz[s][t].z * bargak_setra * 1.5;
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

	dim.c = 0;
	dim.l = 0;
	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		dim.c = valuescount(line);
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
			m[ar[1]][ar[0]].x = ar[3];
			m[ar[1]][ar[0]].y = ar[4];
			m[d.l - ar[1] - 1][ar[0]].z = ft_atoi(pp[ar[0]]);
			ar[3] += (bs * 3 / 1.5);
			ar[4] -= (bs);
		}
		ar[5] -= (bs * 3 / 1.5);
		ar[6] -= (bs);
		ar[3] = ar[5];
		ar[4] = ar[6];
		ar[0] = -1;
	}
	return (m);
}

int	main(int ac, char **av)
{
	float		bargak_setra;
	int			counter;
	t_dimen		dim;
	t_guhuza	**matriz;
	t_winint	g;

	if (ac != 2)
		return (0);
	counter = 0;
	g = graf_init();
	dim = dim_formater(av[1]);
	bargak_setra = bargaksetra(dim.c, dim.l, dim, av[1]);
	matriz = malloc(sizeof(t_guhuza *) * dim.l);
	while (counter < dim.l)
	{
		matriz[counter] = malloc(sizeof(t_guhuza) * dim.c + 1);
		counter++;
	}
	matriz = calc_mesh(dim, bargak_setra, av[1], matriz);
	y_updater(dim, matriz, bargak_setra);
	fil_de_fer(dim, matriz, g.img);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.img.img, 0, 0);
	mlx_loop(g.mlx);
}
