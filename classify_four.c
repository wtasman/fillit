/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whickey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:44:25 by whickey           #+#    #+#             */
/*   Updated: 2016/11/05 22:46:44 by whickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	is_normal_l(unsigned short tet)
{
	if (!(tet ^ 35008) || !(tet ^ 17504) || !(tet ^ 8752) || !(tet ^ 2188) \
	|| !(tet ^ 1094) || !(tet ^ 547))
		return (35008);
	else
		return (0);
}

unsigned short	is_upward_l(unsigned short tet)
{
	if (!(tet ^ 11776) || !(tet ^ 5888) || !(tet ^ 736) || !(tet ^ 368) \
	|| !(tet ^ 46) || !(tet ^ 23))
		return (11776);
	else
		return (0);
}

unsigned short	is_upside_down_l(unsigned short tet)
{
	if (!(tet ^ 50240) || !(tet ^ 25120) || !(tet ^ 12560) || !(tet ^ 3140) \
	|| !(tet ^ 1570) || !(tet ^ 785))
		return (50240);
	else
		return (0);
}

unsigned short	is_downward_l(unsigned short tet)
{
	if (!(tet ^ 59392) || !(tet ^ 29696) || !(tet ^ 3712) || !(tet ^ 1856) \
	|| !(tet ^ 232) || !(tet ^ 116))
		return (59392);
	else
		return (0);
}
