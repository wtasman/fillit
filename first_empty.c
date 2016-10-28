#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"
int first_empty(char **square, int size)
{
	int i;
	int j;
	int flag;
	//find first line that contains only zeros reading only to the size * size position
	//so that we can call this function for assigning the next tetrimino
	i = 0;
	j = 0;
	flag = 0;
	while (i < 25)//was 28
	{
		while (j < ((size * size) - 1) && !flag)//was size*size
		{
			if (square[i][j] != '0')//this stops at first 0
				flag = 1;	
			j++;
		}
		if(!flag)
		{
			return i;
		}
		flag = 0;
		i++;
	}
//	printf("ERROR FIRST_EMPTY\n");
	return 99;
}
/*
int main()
{
	char **test;
	test = (char **)malloc(sizeof(char *) * 500);
	test = ft_memset(test, 0, 500);
	int i = 0;
	while (i < 499)
	{
		test[i] = (char *)malloc(sizeof(char) * 500);
		test[i] = ft_memset(test[i], '0', 500);
		i++;
	}
	printf("Segfault\n");
	printf("%d\n", first_empty(test, 4));
}*/
