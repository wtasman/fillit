int fit_char(char *bitmap_str, char **square_str, int size)
{
	int i;
	int flag;

	i = 0;
	flag = 0
	while (bitmap_str[i])
	{
		if (bitmap_str[i]=='1' && (conflicts(square_str, i+size) || conflicts(square_str, i-size) || conflicts(square_str, i+1) || conflicts(square_str, i-1)))
			flag = 1;//it is in contact with the square's pieces
		if (conflicts(square_str, i) && bitmap_str[i] == '1')
			return 0;//conflict
		i++;
	}
	if (flag)
		return 1;
	return 0;
}

The bitmap_str can be represented as a (char * )string for each tetrimino but for all tetriminoes it will need to be a (char **)
The square_str will have to be a char ** because each string will need to contain all previous tetrimino placements.

Each time the size is increased, square should be malloc'd to square + 1 x square + 1


Build a matrix comparing function to find if they intersect in any of the character arrays

count from 0
if the checking bitmap char at i is '1' 
check all other solution bitmaps at i
input  solution
0100	00000000
		00000000
		00000000
		00000000
read through iterating the height index for the solution array and if any of them are equal to '1' return conflict





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


char *fix_offset(char *tet_string, int size)
{
	int i;

	i = 0;
	char *offset_string;
	if (size == 2)
	{
		offset_string = (char *)malloc(sizeof(char) * 4);
		while (tet_string[i] && i < 6)
		{
			if (i != 2 && i != 3)
				offset_string = tet_string[i];
			i++;
		}
		return offset_string;
	}
	if (size == 3)
	{
		offset_string = (char *)malloc(sizeof(char) * 9);
		while (tet_string[i] && i < 12)
		{
			if (i != 3 && i != 7)
				offset_string = tet_string[i];
			i++;
		}
		return offset_string;
	}
	if (size == 4)
	{
		return tet_string;
	}
	offset_string = (char *)malloc(sizeof(char) * (size * size) + 1);
	max = size * size;
	while (tet_string[i])
	{
		if (i % size == 0)
		{
			while (h < (size-4))
			{
				offset_string[j++] = '0';
				h++;
			}
		}

		offset_string[j] = tet_string[i];
		i++;
		j++;
	}
	h = 0;
	while (h < ((size - 4) * size))
	{
		offset_string[j++] = '0';
		h++;
	}
	return offset_string;
}
// it's probably faster to regenerate the string from the bitmap than copy malloc shift each time
//

WHEN PASSED THE ORIGINAL BITMAP as unsigned short
copy over string char by char until i %size == 0
then add (size - 4) zeros at that place and resume copying/iterating
also need to add ((size-4) * size) zeros at the end




















