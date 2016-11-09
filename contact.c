/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:46:22 by whickey           #+#    #+#             */
/*   Updated: 2016/11/07 23:46:25 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	row_check(char **solution, int number, int index)
{
	int j;

	j = 0;
	while (j < number)
	{
		if (solution[j][index] == '1')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flag(char **solution, int number, int size)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!flag && (i % size - 1 != 0 || i == 0) && ((i + 1 < size * size)
				&& (row_check(solution, number, i + 1))))
		flag = 1;
	if (!flag && (i % (size) != 0) && (i - 1 >= 0)
			&& row_check(solution, number, i - 1))
		flag = 1;
	if (!flag && (i - size >= 0) &&
			row_check(solution, number, i - size))
		flag = 1;
	if (!flag && (i + size < size * size) &&
			row_check(solution, number, i + size))
		flag = 1;
	return (flag);
}

int	contact(char **solution, int number, int size)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (j < number)
	{
		while (i < size * size)
		{
			if (solution[j][i] == '1')
			{
				flag = ft_flag(solution, number, size);
				if (!flag)
					return (0);
				flag = 0;
			}
			i++;
		}
		j++;
		i = 0;
		flag = 0;
	}
	return (1);
}
