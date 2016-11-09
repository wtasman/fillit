/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 23:35:03 by whickey           #+#    #+#             */
/*   Updated: 2016/11/07 23:21:59 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int g_x;

void	decrement(char **temp, unsigned short *bitmap_temp)
{
	char			t;
	unsigned short	b;

	b = bitmap_temp[0];
	t = *temp[0];
}

char	**is_fit(char **tet, unsigned short *bit, char **sol, int size)
{
	char			**temp;
	char			**tmp;
	unsigned short	*bitmap_temp;

	if (*(temp = tet))
	{
		bitmap_temp = bit;
		tmp = generate_shifts(*temp, size, get_width(*bitmap_temp));
		while (!is_empty(*tmp, size))
		{
			if (fit_char(*tmp++, sol, size))
			{
				*(sol + g_x++) = *(tmp - 1);
				if (is_fit(++temp, ++bitmap_temp, sol, size))
					return (sol);
				ft_memset(*(sol + g_x-- - 1), '0', size * size);
				decrement(temp--, bitmap_temp--);
			}
		}
		return (0);
	}
	else if ((first_empty(sol, size) == g_x) && contact(sol, g_x, size))
		return (sol);
	else
		return (0);
}
