/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:25:39 by wasman            #+#    #+#             */
/*   Updated: 2016/10/19 14:16:59 by whickey          ###   ########.fr       */
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
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (NULL);
	len--;
	tmp = ft_memset(tmp, '0', len);
	if (tet[len] != '1')
	{
		while(tmp[i+1] != '\0')
		{
			tmp[i + 1] = tet[i];
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
