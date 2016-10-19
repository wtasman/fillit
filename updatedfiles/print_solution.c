void print_solution(char **solution)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (solution[i])
	{
		while(solution[i][j])
		{
			if (solution[i][j] == '1')
				solution[i][j] = i + 'A';
			j++;
		}
		i++;
	}
	while (solution[i])
	{
		while(solution[i][j])
		{
			ft_putchar(solution[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
