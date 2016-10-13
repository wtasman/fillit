/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:45:14 by wasman            #+#    #+#             */
/*   Updated: 2016/10/13 16:09:46 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	ft_btoi(char *str)
{
	unsigned short	nbr;
	int				i;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr *= 2;
		if (str[i] == '1')
			nbr += 1;
		i++;
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr(ft_btoi(argv[1]));
	return (0);
}
