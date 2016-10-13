int is_valid(char *str)
{
	int i;
	int blockcount;
	int tetcount;

	i = 0;
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
		}
		if(str[i] == '#')//count the tetrimino block
			blockcount++;
		i++;//iterate to next char
	}
	//need to check somehow that it returns 0 if it gets to a null before the empty
	return tetcount;//returns the number of tetriminos or 0 if invalid.
}
