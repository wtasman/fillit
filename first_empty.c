/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:29:36 by wasman            #+#    #+#             */
/*   Updated: 2016/11/06 01:32:25 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	nth_empty(char **square, int size, int ignore)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < 25)
	{
		while (j < ((size * size) - 1) && !flag)
		{
			if (square[i][j] != '0')
				flag = 1;
			j++;
		}
		if (!ignore && !flag)
			return (i);
		if (!flag)
			ignore--;
		flag = 0;
		i++;
	}
	return (99);
}

int	first_empty(char **square, int size)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < 25)
	{
		while (j < ((size * size) - 1) && !flag)
		{
			if (square[i][j] != '0')
				flag = 1;
			j++;
		}
		if (!flag)
			return (i);
		flag = 0;
		j = 0;
		i++;
	}
	return (99);
}
