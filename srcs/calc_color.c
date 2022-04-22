/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:05:59 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/22 18:13:24 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	pos(char c)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if ("0123456789ABCDEF"[i] == c)
			return (i);
		else if ("0123456789abcdef"[i] == c)
			return (i);
	}
	return (-1);
}

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static char	*ft_pro_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i + 3));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i + 3));
	return (NULL);
}

static int	hex_decode(char *f)
{
	int	i;
	int	res;
	int	size;

	i = -1;
	res = 0;
	size = ft_strlen(f);
	while (++i < size && f[i] != '\0')
		res = res + (pos(f[i]) * ft_recursive_power(16, (size - i - 1)));
	return (res);
}

int	color_reader(char *s)
{
	int		res;
	char	*f;

	res = 0;
	f = ft_pro_strchr(s, ',');
	if (f == NULL)
		return (-1);
	res = hex_decode(f);
	return (res);
}
