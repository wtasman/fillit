#include "fillit.h"

char *get_last_tetrimino(char *str)
{
	char *ret;
	int	i;
	int j;

	j = 0;
	i = -20;
	ret = ft_strnew(17);
	while (str[i])
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
//add functionality such that get_last_tetrimino reads the last 
//16 bytes and null terminates ignoring unwanted chars



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
	if (!str) //null strings should fail
		return 0;
	while (str[i])//while there are characters to parse
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')//if not valid char
			return 0;
		if ((i + 1) % 5 == 0 && str[i] != '\n')//if the 5 char is not newline
			return 0;
		if ((i + 1) % 21 == 0)//if the 5th line
		{
			if (str[i] != '\n' || blockcount != 4)//is not a newline or not 4 '#'
				return 0;
			blockcount = 0;//reset count for next tetrimino
			//reached the end of a valid tetrimino now add it to the array.
			tetriminoes[i] = classify(ft_btoi(get_last_tetrimino(&str[i])));
		}
		if(str[i] == '#')//count the tetrimino block
			blockcount++;
		i++;//iterate to next char
	}
	//need to check somehow that it returns 0 if it gets to a null before the empty
	return tetriminoes;//returns the number of tetriminos or 0 if invalid.
}
