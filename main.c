#include "fillit.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	char	*tet_buffer;
	char	**tet_array;
	char	**tet_solution;
	int		i;
	unsigned short *bitmap_array;

	if(!(tet_buffer = readem(argv[1])))
			return 0;
//	i = ft_strlen(tet_buffer);
//	tet_buffer[i] = '\n';//This is a fucking hack. Fix is_valid
//	tet_buffer[i+1] = 0; // ^
	i = 0;	
	bitmap_array = is_valid(tet_buffer);//error in is_valid seems to be rerunning 
//	printf("IT MADE IT HERE!\n");
	tet_array = (char **)malloc(sizeof(char*) * 27);
	tet_solution = (char **)malloc(sizeof(char*) * 27);
	tet_array = ft_memset(tet_array, 0, 27);
	tet_solution = ft_memset(tet_solution, 0, 27);
	//tet_solution[i] = (char *)malloc((sizeof(char) * 1));
	//tet_solution[i][i] = '9';
	//tet_array[i] = (char *)malloc(sizeof(char)*500);
	i++;
//	printf("MALLOC IS FINE \n");
	while (i < 27)
	{
		tet_solution[i] = (char *)malloc(sizeof(char)*500);
		tet_array[i] = (char *)malloc(sizeof(char)*500);
		tet_solution[i] = ft_memset(tet_solution[i], '0', 500);
		tet_array[i] = ft_memset(tet_array[i], '0', 500);
		i++;
	}
//	tet_solution[0][0] = '9';
//	tet_array[0][0] = '9';
//	tet_array[27] = 0;
	i = 0;
//	printf("WHAT is the problem?\n");
	while (bitmap_array[i])
	{
		tet_array[i] = itoa_base(bitmap_array[i], 2);
	//	tet_array[i][16] = 0;
	//	printf("STRING LENGTH : %zu\n",ft_strlen(tet_array[i]));
	//	printf("IS THIS NULL? : %c\n",tet_array[i][16]);//REDUNDANT CHECK OF BTOI
//		printf("BITMAP : %hu \n TET : %s\n",bitmap_array[i],tet_array[i]);
		i++;
	}
	tet_array[i] = 0;
	//printf("THIS SHOULD ONLY BE 16 BITS: %s\n", tet_array[0]);
	if (tet_array)
	{
		if((tet_solution = solve(tet_array, bitmap_array, ++tet_solution)))
		{
//			printf("%s\n",tet_solution[0]);
//			printf("%s\n",tet_solution[1]);
//			printf("%s\n",tet_solution[2]);
//			printf("%s\n",tet_solution[3]);
//			printf("%s\n",tet_solution[4]);
//			printf("%s\n",tet_solution[5]);
			print_solution(tet_solution);
			return 0;
		}
		return 0;
	}
	else
	{
		ft_putstr("Usage: ...\n");
	}
}
