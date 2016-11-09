/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:25:39 by wasman            #+#    #+#             */
/*   Updated: 2016/11/07 19:13:27 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_on_edge(char *array, int size)
{
	int i;
	int flag;

	i = size - 1;
	flag = 0;
	while (i < (size * size) && !flag)
	{
		if (array[i] == '1')
			flag = 1;
		i += size;
	}
	if (!flag)
		return (0);
	return (1);
}

static int	no(int *i, int *j, int *h)
{
	*i = 0;
	*j = 1;
	*h = -1;
	return (1);
}

static char	*c(int length)
{
	char *r;

	r = ft_strnew(length);
	ft_memset(r, '0', length - 1);
	r[length] = 0;
	return (r);
}

static int	f_l(char *str)
{
	int length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char		*shift(char *t, int size, int width)
{
	char	*r;
	int		i;
	int		j;
	int		h;

	if (!t || t[f_l(t) - 1] == '1' || !(r = c(f_l(t))) || !no(&i, &j, &h))
		return (NULL);
	while ((!(r[ft_strlen(t)] = 0)) && t[i] != '\0')
	{
		if (is_on_edge(t, size))
		{
			if (find_last_one_char(t) + width <= f_l(t) - 1)
			{
				while (++h < width - 1)
				{
					if ((r[j++] = '0') && (i == f_l(t) - 1))
						return (0);
				}
			}
			else
				return (NULL);
		}
		r[j++] = t[i++];
	}
	return (r);
}
