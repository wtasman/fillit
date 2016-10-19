char **solve(char **tet_array, char **tet_solution)
{
	int size = 2;
	char **solution;

	solution = is_fit(tet_array, tet_solution, size++);
	while (size < 14 && !solution)
	{
		size++;
		solution = is_fit(tet_array, tet_solution, size);
	}
	if (size == 14)
		return 0;
	return solution;
}
