/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:36:54 by whickey           #+#    #+#             */
/*   Updated: 2016/11/07 23:40:38 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char				*get_l(char *str)
{
	char	*ret;
	int		i;
	int		j;
	int		blocks;
	int		dots;

	j = 0;
	i = 0;
	blocks = 0;
	dots = 0;
	ret = ft_strnew(17);
	while (str[i] && i < 19)
	{
		if (str[i] == '\n')
			i++;
		if (str[i] == '#' && ++blocks)
			ret[j] = '1';
		if (str[i] == '.' && ++dots)
			ret[j] = '0';
		j++;
		i++;
	}
	ret[j] = 0;
	return ((dots == 12 && blocks == 4) ? ret : 0);
}

static	int				no(int *i, int *j, int *h)
{
	*i = -1;
	*j = 0;
	*h = 0;
	return (1);
}

static unsigned short	cascade(char *str, int i)
{
	return (classify(ft_btoi(get_l(ft_strsub(str, i - 20, 20)))));
}

static unsigned short	*al(void)
{
	unsigned short	*t;

	t = (unsigned short *)malloc(sizeof(unsigned short) * 27);
	ft_memset(t, 0, 27);
	return (t);
}

unsigned short			*is_valid(char *str)
{
	int				i;
	int				j;
	int				b;
	unsigned short	*t;

	if ((!(t = al()) || ft_strlen(str) < 20 || !str || !no(&i, &j, &b)))
		return (0);
	while (str[++i])
	{
		if ((str[i] != '.' && str[i] != '#' && str[i] != '\n') \
			|| (((i + 1 - j) % 5 == 0 && str[i] != '\n')))
			return (0);
		if ((i + 1) % 21 == 0)
		{
			if ((str[i] != '\n' || b != 4) || (!(t[j] = cascade(str, i))))
				return (0);
			if (!(b = 0) && ++j && ++i)
				;
		}
		if (str[i] == '#')
			b++;
	}
	if ((get_l(ft_strsub(str, i - 20, 20)) && (t[j] = cascade(str, i))))
		return (t);
	return (0);
}
