/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:41:26 by wasman            #+#    #+#             */
/*   Updated: 2016/10/14 22:21:24 by wasman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*readem(char *arg)
{
	char	*buf;
	int		fd;
	int		len;

	buf = ft_strnew(BUF_SIZE);
	fd = open(arg, O_RDONLY);
	len = read(fd, buf, BUF_SIZE);
	close(fd);
	return (buf);
}

int	main(int argc, char	**argv)
{
	if (argc == 2)
		ft_putstr(readem(argv[1]));
	return (0);
}
