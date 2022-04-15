/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bargaksetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:19:59 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/15 18:12:00 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

float	bs_zupdater(float bargak_setra, t_dimen d, char *str)
{
	int		*ar;
	char	**pp;
	char	*map;

	ar = (int [3]){-1, d.l, open(str, O_RDWR)};
	while (--ar[1] >= 0)
	{
		map = get_next_line(ar[2]);
		pp = ft_split(map, 32);
		while (++ar[0] < d.c)
		{
			if (ft_atoi(pp[ar[0]]) >= 20 || ft_atoi(pp[ar[0]]) <= -20)
				return (bargak_setra * 0.25);
		}
		ar[0] = -1;
	}
	return (bargak_setra);
}

float	bargaksetra(int columns, int lines, t_dimen d, char *str)
{
	float	bargak_setra;

	bargak_setra = 0;
	if (columns >= lines)
		bargak_setra = columns;
	else
		bargak_setra = lines;
	if (bargak_setra <= 15)
		bargak_setra = 6;
	else if (bargak_setra <= 30)
		bargak_setra = 5;
	else if (bargak_setra <= 45)
		bargak_setra = 4;
	else if (bargak_setra <= 60)
		bargak_setra = 3;
	else if (bargak_setra <= 100)
		bargak_setra = 2;
	else
		bargak_setra = 1;
	bargak_setra = bs_zupdater(bargak_setra, d, str);
	return (bargak_setra);
}
