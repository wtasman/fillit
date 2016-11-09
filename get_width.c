/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:45:24 by wasman            #+#    #+#             */
/*   Updated: 2016/11/06 01:47:22 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_width(unsigned short bitmap)
{
	if (!(bitmap ^ 52224) || !(bitmap ^ 35968) || !(bitmap ^ 19520) ||
			!(bitmap ^ 17600) || !(bitmap ^ 51328) || !(bitmap ^ 19584) ||
			!(bitmap ^ 35904) || !(bitmap ^ 35008) || !(bitmap ^ 50240))
		return (2);
	if (!(bitmap ^ 34952))
		return (1);
	if (!(bitmap ^ 61440))
		return (4);
	if (!(bitmap ^ 58368) || !(bitmap ^ 19968) || !(bitmap ^ 57856) ||
			!(bitmap ^ 36352) || !(bitmap ^ 50688) || !(bitmap ^ 27648) ||
			!(bitmap ^ 11776) || !(bitmap ^ 59392))
		return (3);
	return (0);
}
