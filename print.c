/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:40:42 by whickey           #+#    #+#             */
/*   Updated: 2016/11/08 18:32:11 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_squareroot(int size)
{
	int i;

	i = 0;
	while (i * i != size && i < 15)
	{
		i++;
	}
	if (i == 15)
		return (0);
	return (i);
}

char	**assign_letters(char **solution)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (solution[i])
	{
		while (solution[i][j])
		{
			if (solution[i][j] == '1')
				solution[i][j] = i + 'A';
			j++;
		}
		j = 0;
		i++;
	}
	return (solution);
}

void	print_solution(char **solution)
{
	int i;
	int j;
	int sqrt;
	int flag;

	i = -1;
	j = -1;
	sqrt = ft_squareroot(ft_strlen(solution[0]));
	while (++j < (sqrt * sqrt))
	{
		if (((j % sqrt) == (flag = 0)) && (j != 0))
			ft_putchar('\n');
		while (solution[++i] && !flag)
		{
			if (solution[i][j] != '0')
			{
				flag = 1;
				ft_putchar(solution[i][j]);
			}
		}
		if (!flag)
			ft_putchar('.');
		i = -1;
	}
	ft_putchar('\n');
}
