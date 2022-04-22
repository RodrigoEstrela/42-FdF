/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:20:56 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/02/21 11:52:20 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && ((unsigned char)s1[i] == (unsigned char)s2[i]
			&& ((unsigned char)s1[i]) && ((unsigned char)s2[i])))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
