/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:41:33 by whickey           #+#    #+#             */
/*   Updated: 2016/11/05 22:44:11 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	is_upward_j(unsigned short tet)
{
	if (!(tet ^ 36352) || !(tet ^ 18176) || !(tet ^ 2272) || !(tet ^ 1136) \
	|| !(tet ^ 142) || !(tet ^ 71))
		return (36352);
	else
		return (0);
}

unsigned short	is_normal_z(unsigned short tet)
{
	if (!(tet ^ 50688) || !(tet ^ 25344) || !(tet ^ 3168) || !(tet ^ 1584) \
	|| !(tet ^ 198) || !(tet ^ 99))
		return (50688);
	else
		return (0);
}

unsigned short	is_rotated_z(unsigned short tet)
{
	if (!(tet ^ 19584) || !(tet ^ 9792) || !(tet ^ 4896) || !(tet ^ 1224) \
	|| !(tet ^ 612) || !(tet ^ 306))
		return (19584);
	else
		return (0);
}

unsigned short	is_normal_s(unsigned short tet)
{
	if (!(tet ^ 27648) || !(tet ^ 13824) || !(tet ^ 1728) || !(tet ^ 864) \
	|| !(tet ^ 108) || !(tet ^ 54))
		return (27648);
	else
		return (0);
}

unsigned short	is_rotated_s(unsigned short tet)
{
	if (!(tet ^ 35904) || !(tet ^ 17952) || !(tet ^ 8976) || !(tet ^ 2244) \
	|| !(tet ^ 1122) || !(tet ^ 561))
		return (35904);
	else
		return (0);
}
