#include "fillit.h"
#include <stdio.h>
int conflicts(char **conflicts, int i)
{
	int j;

	j = 0;
	while (j < 26)
	{
		if (conflicts[j][i] == '1')
			return 1;
		j++;
	}
	return 0;
}

int fit_char(char *bitmap_str, char **square_str, int size)
{
	int i;
	int flag;
	int len;

	i = 0;
	flag = 0;
	len = ft_strlen(bitmap_str)-1;
//	printf("FIT_CHAR PRINTS EVERYTIME\n");
	if(!*bitmap_str)
		return 0;
	while (bitmap_str[i])
	{
//		printf("%c\n",bitmap_str[i]);
		if ((0 <= (i+size) <= len) && (bitmap_str[i]=='1') && conflicts(square_str, i+size))
			flag = 1;
		if ((0 <= (i - size) <= len) && (bitmap_str[i]=='1') && conflicts(square_str, i-size))
			flag = 1;
		if ((0 <= (i + 1) <= len) && (bitmap_str[i]=='1') && conflicts(square_str, i+1))
			flag = 1;
		if ((0 <= (i - 1) <= len) && (bitmap_str[i]=='1') && conflicts(square_str, i-1))
			flag = 1;
//		printf("the flag = %d\n", flag);
//		printf("i is %d\n", i);
//		printf("square at 00 : %c\n", square_str[0][i]);
		if (conflicts(square_str, i) && bitmap_str[i] == '1')//shows if tetrimino can be placed here.
			return 0;
		i++;
//		printf("DOES THIS RUN??\n");
	}
//	printf("SEGFAULTS HERE!!!!!!!\n");
	if (flag)
	{
//		printf("FITCHAR RETURNS THAT THE TET FITS!!!\n");
		return 1;
	}
	return 0;
}

char **is_fit(char **tet_array, unsigned short *bitmap_array, char **square_str, int size)
{
	int i;
	char **potential_solution;

	i = 0;
	potential_solution = (char **)malloc(sizeof(char *) * 27);
	while (i < 27)
	{
		potential_solution[i++] = (char *)malloc(sizeof(char) * ((size * size) + 1));
	}
	potential_solution[i] = 0;
//	printf("Segfaults during copy\n");
/*
 *Copy the square_str into potential solution
 *
 */
	i = -1;
	while (++i < size)
		potential_solution[i] = strcpy(potential_solution[i],square_str[i]);
//	printf("Didn't segfault yet!\n");

	if(*tet_array)
	{
		if (first_empty(potential_solution,size) == 0 || fit_char(*tet_array, potential_solution, size))//IF FIRST TETRIMINO TO BE PLACED OR THE TETRIMINO FITS IN THE SOLUTION
		{//EXECUTES FOR ALL PROMISING CHILD NODES
//			printf("This printssss\n");
//			printf("FIRST EMPTY = %d\n", first_empty(potential_solution,size));
			*(potential_solution + first_empty(potential_solution, size)) = *tet_array++; //ASSIGNS THE TETRIMINO TO THE SOLUTION & INCREMENTS TO THE NEXT TETRIMINO (TET_ARRAY)
			printf("TET_ARRAY HAS BEEN ASSIGNED: %s at SIZE: %d\n", *(tet_array-1), size);
			bitmap_array++;//MOVES TO THE NEXT BITMAP TO KEEP WIDTH CORRECT FOR SHIFTING
//			printf("Before calling is_fit recursively: %s\n",*tet_array);
			potential_solution = is_fit(tet_array, bitmap_array, potential_solution, size);//CALL THE NEXT TETRIMINO WITH THE SAME RECURSIVE CHECK
			return potential_solution;

//			if (solution is not found then shift the first and recurse)
//				is_fit(shift())

//			return square_str;//IF ISFIT HAS RETURNED RETURN THE SOLUTION;
		}
		else
		{
//			printf("THE TETRIMINO DID NOT FIT AND WAS NOT THE FIRST TETRIMINO PLACED\n");
			if((*tet_array = shift(*tet_array, size, get_width(*bitmap_array++))))
			{	
//				printf("DOES IS_FIT'S ELSE STATEMENT RUN???\n");
//				printf("This is going to be passed to is_fit: %s\n", *tet_array);
				potential_solution = is_fit(tet_array, bitmap_array, potential_solution, size);
				return potential_solution;
				printf("THIS RETURN 0 KILLS EVERYTHING\n");
				return 0;
			}
		}
	}
	return square_str;
}

char **fix_all(char **tet_array, int size)
{
	char **offset_tet;
	int i = -1;
	int flag = 0;
	char **ptr;

	offset_tet = (char **)malloc(sizeof(char *) * 27);
	offset_tet = ft_memset(offset_tet, 0, 27);
	ptr = offset_tet;
//	while (tet_array[++i] != NULL)//why does this copy all 27?
//		offset_tet[i] = ft_strdup(tet_array[i]);
	//this copies regardless of whether it can be offset correctly, which is incorrect
//	printf("%d\n", i);
	while (*tet_array && !flag)
	{
		if(!(*offset_tet = fix_offset(*tet_array, size)))
		{
//			printf("This shouldn't be true the loop should fail already.\n");
			return 0;
		
		}
//		if (*offset_tet == NULL)
//			flag = 1;
//		printf("TET = %s OFFSET = %s\n",*tet_array++, *offset_tet++);
		offset_tet++;
		tet_array++;
	}	
//	printf("fix all runs\n");
	return ptr;
}

int num_of_tets(unsigned short *bitmap_array)
{
	int num = 0;
	while (*bitmap_array++)
		num++;
	return num;
}

char **solve(char **tet_array, unsigned short *bitmap_array, char **tet_solution)
{
	int size = 2;
	char **solution;
	char **offset_tet;
	//change all tet_array members to their offset counterparts
	if((offset_tet = fix_all(tet_array, size)))
	{
//		printf("Offset fix_all returns valid. is_fit will be called with size = 2\n");
//		printf("Offset should fix_all should fail for size 2 what is *offset? : %s\n", *offset_tet);
		if((solution = is_fit(offset_tet, bitmap_array, tet_solution, size)))
			return solution;
	}
//	printf("Size iteration loop starts here.\n");
	while (size < 14)//if a valid solution is found return, don't continue iterating size
	{
//		printf("Size is being incremented\n");
		size++;
		if((offset_tet = fix_all(tet_array, size)))
		{
//			printf("OFFSET IS VALID. TESTING IS_FIT...\n");
//			printf("WHY IS THIS NULL? : %s %s\n", *offset_tet, *tet_array);
			if((solution = is_fit(offset_tet, bitmap_array, tet_solution, size)))
			{
				printf("Solution wasn't null\n");
				//printf("%d\n", first_empty(offset_tet, size));
/*				printf("%s\n", offset_tet[0]);
				printf("%s\n", offset_tet[1]);
				printf("%s\n", offset_tet[2]);
				printf("%s\n", offset_tet[3]);
				printf("%s\n", offset_tet[4]);
				printf("%s\n", offset_tet[5]);
				printf("%s\n", offset_tet[6]);
*/
				if(first_empty(solution, size)==num_of_tets(bitmap_array)) //first_empty(offset_tet, size))	
				{
					printf("Does it think it found a solution?\n");
					return solution;
				}

			}
		}
//		printf("FIRST EMPTY SOLUTION : %d\n", first_empty(solution, size));
//		printf("FIRST EMPTY TET_ARRAY : %d\n", first_empty(tet_array, size));
//		if (first_empty(solution, size)==first_empty(tet_array, size))
//			return solution;
		printf("Solution was not found at size: %d\n",size);
	}
	if (size == 14)
		return 0;
	return solution;
}

int ft_squareroot(int size)
{
	int i = 0;
	while (i * i != size && i < 15)
	{
		i++;
	}
	if(i == 15)
		return 0;
	return i;
}


void print_solution(char **solution)
{
	int i;
	int j;
	int sqrt;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	sqrt = ft_squareroot(ft_strlen(solution[i]));
	printf("Print solution runs\n");
	while (solution[i])
	{
		while(solution[i][j])
		{
			if (solution[i][j] == '1')
			{	
				solution[i][j] = i + 'A';
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	
	while (j < (sqrt*sqrt))
	{	
		if ((j % sqrt == 0) && (j != 0))
			ft_putchar('\n');
		while(solution[i] && !flag && i < sqrt)
		{
			if (solution[i][j] != '0')
			{
				flag = 1;
				ft_putchar(solution[i][j]);
			}
			i++;
		}
		if (!flag)
			ft_putchar('.');
		i = 0;
		flag = 0;
		j++;
	}
}
