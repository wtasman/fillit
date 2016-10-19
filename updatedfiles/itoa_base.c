#include <stdlib.h>
#include <stdio.h>

int     ft_count_digits(int x)
{
	int digits;

	digits = 0;
	if (!x)
		return (1);
	while (x)
	{
		x /= 10;
		digits++;
	}
	return (digits);
}

char    *itoa_base(int x, int base)
{
	char        *b;
	long long   i;
	int         j;
	char		*num;

	i = x;
	num = "0123456789abcdef";
	if (x < (j = 0))
		j++;
	if ((b = (char *)malloc(sizeof(char) * (ft_count_digits(x) + j + 1))))
	{
		if (i < 0)
		{
			*b = '-';
			i *= -1;
		}
		*(b += ft_count_digits(x) + j) = '\0';
		*--b = (num[i % base]);
		while (i /= base)
			*--b = (num[i % base]);
		if (x < 0)
			return (--b);
		return (b);
	}
	return (0);
}

int main()
{
	char *test = itoa_base(7007,2);
	printf("%s\n",test);


}
