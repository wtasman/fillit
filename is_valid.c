char *get_last_tetrimino(char *str)
{
	//remove newlines  and swap # and . for 1 and 0
	char *ret;

	ret = ft_strnew(17);
	while (str[i])
	{
		if str(str[i]=='\n')
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



int is_valid(char *str)
{
	int i;
	int j;
	int blockcount;
	int tetcount;
	subtypes tetriminoes[19];

	i = 0;
	j = 0;
	blockcount = 0;
	tetcount = 0;
	if (!str) //null strings should fail
		return 0;
	while (str[i])//while there are characters to parse
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')//if not valid char
			return 0;
		if ((i + 1) % 5 == 0 && str[i] != '\n')//if the 5 char is newline
			return 0;
		if ((i + 1) % 21 == 0)//if the 5th line
		{
			if (str[i] != '\n' || blockcount != 4)//is not a newline or not 4 '#'
				return 0;
			blockcount = 0;//reset count for next tetrimino
			tetcount++;
			tetriminoes[classify(ft_btoi(get_last_tetrimino(ft_substr(str[i-16],16))))].count += 1;
			//i counter might be off by 1
			
		
		
		
		
		
		
		
		}
		if(str[i] == '#')//count the tetrimino block
			blockcount++;
		i++;//iterate to next char
	}
	//need to check somehow that it returns 0 if it gets to a null before the empty
	return tetcount;//returns the number of tetriminos or 0 if invalid.
}
