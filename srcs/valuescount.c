/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valuescount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:58:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/19 16:51:12 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	valuescount(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (!(ft_isspace(s[i])) && s[i] != '\0')
			i++;
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		count++;
	}
	if (s[i - 2] != 32 && s[i - 1] == '\n')
		count--;
	return (count);
}
