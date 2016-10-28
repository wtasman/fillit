#include "fillit.h"
#include <stdio.h>
 char *fix_offset(char *tet_string, int size)
{
	int i;
	int max;
	int h;
	int j;

	i = 0;
	j = 0;
	h = 0;
	char *offset_string;
	if (!(*tet_string))
	{
		printf("THIS SHOULDN'T RETURN\n");
		return 0;
	}
	if (size == 2)
	{
		offset_string = (char *)malloc(sizeof(char) * 5);
		if (ft_strcmp(tet_string, "1100110000000000") == 0)
		{
			offset_string[0] = '1';
			offset_string[1] = '1';
			offset_string[2] = '1';
			offset_string[3] = '1';
			offset_string[4] = 0;
			return (offset_string);
		}
		return NULL;
	}
	if (size == 3)
	{
		j = 0;
		if (ft_strcmp(tet_string, "1111000000000000") == 0 || ft_strcmp(tet_string, "1000100010001000")==0)
			return NULL;
		offset_string = (char *)malloc(sizeof(char) * 10);
		if (ft_strcmp(tet_string, "0001111000000000")==0)
			return "001111000";
		while (tet_string[i] && i < 12)
		{
			if (i != 3 && i != 7)
				offset_string[j++] = tet_string[i];
			i++;
		}
		offset_string[9] = 0;
		return offset_string;
	}
	if (size == 4)
	{
		return tet_string;
	}
	if (size > 4)
	{
		i = 0;
		if((offset_string = (char *)malloc(sizeof(char) * (size * size) + 1)))
		{
		//	offset_string = ft_memset(offset_string, '0', size*size);
			while (i < 17)
			{
			
				h=0;
				if (i != 4 && i!= 8 && i != 12 && i != 16 && tet_string[i])
					offset_string[j++] = tet_string[i];
				else
				{
					while(h < (size - 4))
					{
						offset_string[j++] = '0';
						h++;
					}
					if (tet_string[i])
						offset_string[j++] = tet_string[i];
				}
				i++;
			}
			h = 0;
			while (h < ((size - 4) * size)) //size -4 is the number of rows size is number of columns
			{
				offset_string[j++] = '0';
				h++;
			}
			offset_string[size*size] = 0;
			return offset_string;
		}
	}
	return "WHY?";
}
