/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bargaksetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:19:59 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/13 10:21:06 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	bargaksetra(int columns, int lines)
{
	int	bargak_setra;

	bargak_setra = 0;
	if (columns >= lines)
		bargak_setra = columns;
	else
		bargak_setra = lines;
	if (bargak_setra <= 15)
		bargak_setra = 16 * 2;
	else if (bargak_setra <= 30)
		bargak_setra = 9 * 2;
	else if (bargak_setra <= 45)
		bargak_setra = 6 * 2;
	else if (bargak_setra <= 60)
		bargak_setra = 3 * 2;
	else if (bargak_setra <= 100)
		bargak_setra = 2 * 2;
	else
		bargak_setra = 1 * 2;
	return (bargak_setra);
}
