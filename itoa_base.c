/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:25:13 by whickey           #+#    #+#             */
/*   Updated: 2016/11/06 03:26:04 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_digits(int x, int base)
{
	int digits;

	digits = 0;
	if (!x)
		return (1);
	while (x)
	{
		x /= base;
		digits++;
	}
	return (digits);
}

char	*itoa_base(int x, int base)
{
	char		*b;
	long long	i;
	char		*num;
	char		*ptr;

	i = x;
	num = "0123456789abcdef";
	if ((b = (char *)malloc(sizeof(char) * (17))))
	{
		ptr = ft_memset(b, '0', 17);
		*(b += 16) = '\0';
		*--b = (num[i % base]);
		while (i /= base)
			*--b = (num[i % base]);
		return (ptr);
	}
	return (0);
}
