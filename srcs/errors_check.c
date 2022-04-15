/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:07:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/15 17:11:54 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	error_check(int ac, char *str)
{
	if (ac != 2)
		return (0);
	if (ft_strchr(str, '.') == NULL)
		return (0);
	if (ft_strncmp(ft_strchr(str, '.'), ".fdf\0", 5) != 0)
		return (0);
	return (1);
}
