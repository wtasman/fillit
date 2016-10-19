#include <stdio.h>

int find_last_one(unsigned short bitmap)
{
	int count = -1;
	unsigned short x = (bitmap ^ (bitmap & (bitmap - 1)));
	if (!(bitmap ^ 0))
			return 0;
	while (x)
	{
		count++;
		x /= 2;
	}
	return count;
}

int find_first_one(unsigned short bitmap)
{
	int count = 0;
	while (bitmap >>= 1)
		count++;
	return count;
}
int find_last_one_char(char *bitmap)
{
	int length = ft_strlen(bitmap);
	int i = length;
	while (i && bitmap[i] != '1')
		i--;
	return (length - i);
}
int find_first_one_char(char *bitmap)
{
	int length = ft_strlen(bitmap);
	int i = 0;
	while (bitmap[i] != '1' && i < length)
		i++;
	return (ft_strlen(bitmap) - i);
}





int main()
{
	printf("%d\n", find_last_one(562));
	printf("%d", find_first_one(562));
}
