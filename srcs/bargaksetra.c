/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bargaksetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:19:59 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/19 16:41:06 by rdas-nev         ###   ########.fr       */
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
		bargak_setra = 8;
	else if (bargak_setra <= 30)
		bargak_setra = 7;
	else if (bargak_setra <= 45)
		bargak_setra = 6;
	else if (bargak_setra <= 60)
		bargak_setra = 5;
	else if (bargak_setra <= 100)
		bargak_setra = 4;
	else if (bargak_setra <= 200)
		bargak_setra = 3;
	else if (bargak_setra <= 450)
		bargak_setra = 0.1;
	else
		bargak_setra = 2;
	return (bargak_setra);
}
