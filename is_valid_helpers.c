/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:25:37 by whickey           #+#    #+#             */
/*   Updated: 2016/11/06 19:28:11 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short (*g_p[19]) (unsigned short);

int				classify(unsigned short value)
{
	int i;

	i = 0;
	g_p[0] = &is_square;
	g_p[1] = &is_vertical_straight;
	g_p[2] = &is_horizontal_straight;
	g_p[3] = &is_normal_t;
	g_p[4] = &is_left_t;
	g_p[5] = &is_right_t;
	g_p[6] = &is_upside_down_t;
	g_p[7] = &is_normal_j;
	g_p[8] = &is_downward_j;
	g_p[9] = &is_upside_down_j;
	g_p[10] = &is_upward_j;
	g_p[11] = &is_normal_z;
	g_p[12] = &is_rotated_z;
	g_p[13] = &is_normal_s;
	g_p[14] = &is_rotated_s;
	g_p[15] = &is_normal_l;
	g_p[16] = &is_upward_l;
	g_p[17] = &is_upside_down_l;
	g_p[18] = &is_downward_l;
	while (i < 19 && ((((*g_p[i])(value)) == 0)))
		i++;
	return (i == 19 ? (0) : ((*g_p[i])(value)));
}

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
