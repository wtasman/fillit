/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:54:12 by wasman            #+#    #+#             */
/*   Updated: 2016/10/19 15:59:28 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*shift(char *tet)
{
	int	max;
	int	len;
	char	*tmp;
	int	i;

	max = 0;
	len = 0;
	i = 0;
	while (tet[len] != '\0')
		len++;
	if (len == 0)
		return (NULL);
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (NULL);
	len--;
	tmp = ft_memset(tmp, '0', len);
	if (tet[len] != '1')
	{
		while(tmp[i + 1] != '\0')
		{
			tmp[i] = tet[i];
			i++;
		}
		return (tmp);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(shift(argv[1]));
	ft_putchar('\n');
	return (0);
}
