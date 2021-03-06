/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bargaksetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:19:59 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/20 11:32:42 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

float	bargaksetra(int columns, int lines)
{
	float	bargak_setra;

	bargak_setra = 0;
	if (columns >= lines)
		bargak_setra = columns;
	else
		bargak_setra = lines;
	if (bargak_setra <= 15)
		bargak_setra = 21;
	else if (bargak_setra <= 30)
		bargak_setra = 18;
	else if (bargak_setra <= 45)
		bargak_setra = 15;
	else if (bargak_setra <= 60)
		bargak_setra = 12;
	else if (bargak_setra <= 100)
		bargak_setra = 9;
	else if (bargak_setra <= 250)
		bargak_setra = 6;
	else if (bargak_setra <= 450)
		bargak_setra = 3;
	else
		bargak_setra = 1;
	return (bargak_setra);
}
