int main(int argc, char **argv)
{
	char	*tet_buffer;
	char	**tet_array;
	char	**tet_solution;
	int		i;

	i = 0;
	tet_buffer = readem(argv[1]);
	if ((tet_array = is_valid(tet_buffer))
	{
	//while solve doesn't have a solution:
		if(solve(tet_array, tet_solution))
			print_solution(tet_solution);
	}
	else
	{
		ft_putstr("Usage: ...\n");
	}
}
