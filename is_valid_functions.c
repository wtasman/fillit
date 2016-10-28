#include "fillit.h"
#include <stdio.h>
unsigned short (*p[19]) (unsigned short);

int classify(unsigned short value)
{
	int i;

	i = 0;
	p[0] = &is_square;
	p[1] = &is_vertical_straight;
	p[2] = &is_horizontal_straight;
	p[3] = &is_normal_t;
	p[4] = &is_left_t;
	p[5] = &is_right_t;
	p[6] = &is_upside_down_t;
	p[7] = &is_normal_j;
	p[8] = &is_downward_j;
	p[9] = &is_upside_down_j;
	p[10] = &is_upward_j;
	p[11] = &is_normal_z;
	p[12] = &is_rotated_z;
	p[13] = &is_normal_s;
	p[14] = &is_rotated_s;
	p[15] = &is_normal_l;
	p[16] = &is_upward_l;
	p[17] = &is_upside_down_l;
	p[18] = &is_downward_l;

	while (((((*p[i]) (value))==0)) && i < 19)
		i++;
	if (i == 19)
		return 0;
	return ((*p[i]) (value));
}


unsigned short  ft_btoi(char *str)
{
	unsigned short  nbr;
	int             i;

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


char *get_last_tetrimino(char *str)
{
	char *ret;
	int	i;
	int j;

	j = 0;
	i = 0;
	ret = ft_strnew(17);
	while (str[i]&& i < 19)
	{
		if (str[i]=='\n')
			i++;
		if(str[i]=='#')
			ret[j] = '1';
		else
			ret[j] = '0';
		j++;
		i++;
	}
	ret[j] = 0;
	return ret;
}

unsigned short *is_valid(char *str)
{
	int i;
	int j;
	int blockcount;
	unsigned short *tetriminoes;

	i = 0;
	j = 0;
	blockcount = 0;
	if (!(tetriminoes = (unsigned short *)malloc(sizeof(unsigned short) * 27)))
		return 0;
	tetriminoes = ft_memset(tetriminoes, 0, 27);
	if (!str)
		return 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return 0;
		if (((i + 1 - j) % 5 == 0 && str[i] != '\n'))
		{
			return 0;
		}
		if ((i + 1) % 21 == 0)
		{
			if (str[i] != '\n' || blockcount != 4)
				return 0;
			blockcount = 0;
			if (!(tetriminoes[j] = classify(ft_btoi(get_last_tetrimino(ft_strsub(str,i-20,20))))))
			{
				return 0;
			}
			printf("TETRIMINO ARRAY ASSIGNMENT : %d : %d\n", j, tetriminoes[j]);
			j++;
			i++;
		}
		if(str[i] == '#')
			blockcount++;
		i++;
	}
	tetriminoes[j] = classify(ft_btoi(get_last_tetrimino(ft_strsub(str,i-20,20))));
	return tetriminoes;
}
