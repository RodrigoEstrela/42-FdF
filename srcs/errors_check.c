/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:07:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/22 13:07:05 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	file_exists(char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
	if (fd == -1)
		return (-1);
	return (0);
}

int	error_check(int ac, char *str)
{
	if (ac != 2)
	{
		ft_printf("\n\e[0;31mWRONG ARGUMENT NUMBER!\n\n");
		return (0);
	}
	if (ft_strchr(str, '.') == NULL)
	{
		ft_printf("\n\e[0;31mNO FILE EXTENSION\n\n");
		return (0);
	}
	if (ft_strncmp(ft_strchr(str, '.'), ".fdf\0", 5) != 0)
	{
		ft_printf("\n\e[0;31mFILE EXTENSION MUST BE .fdf!\n\n");
		return (0);
	}
	else if (file_exists(str) == -1)
	{
		ft_printf("\n\e[0;31mFILE DOESN'T EXIST!\n\n");
		return (0);
	}
	return (1);
}
