int is_empty(char **square, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (square[i][j++] == '1')
				return 0;
		}
		i++;
	}
	return 1;
}
