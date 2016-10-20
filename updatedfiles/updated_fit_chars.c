#include "fillit.h"

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

	i = 0;
	flag = 0;
	while (bitmap_str[i])
	{
		if (bitmap_str[i]=='1' && (conflicts(square_str, i+size) || conflicts(square_str, i-size) || conflicts(square_str, i+1) || conflicts(square_str, i-1)))
			flag = 1;
		if (conflicts(square_str, i) && bitmap_str[i] == '1')
			return 0;
		i++;
	}
	if (flag)
		return 1;
	return 0;
}

char *fix_offset(char *tet_string, int size)
{
	int i;
	int j;
	int h;
	int max;

	i = 0;
	j = 0;
	h = 0;
	max  = 0;
	char *offset_string;
	if (size == 2)
	{
		offset_string = (char *)malloc(sizeof(char) * 4);
		while (tet_string[i] && i < 6)
		{
			if (i != 2 && i != 3)
				offset_string[j++] = tet_string[i++];
		}
		return offset_string;
	}
	if (size == 3)
	{
		offset_string = (char *)malloc(sizeof(char) * 9);
		while (tet_string[i] && i < 12)
		{
			if (i != 3 && i != 7)
				offset_string[j++] = tet_string[i++];
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
