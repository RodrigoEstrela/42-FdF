/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:07:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/25 12:10:49 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	file_exists(char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	line = (get_next_line(fd));
	if (line == NULL)
	{
		close(fd);
		return (-1);
	}
	close(fd);
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
		ft_printf("\n\e[0;31mFILE DOESN'T EXIST OR IS EMPTY! \n\n");
		return (0);
	}
	return (1);
}
