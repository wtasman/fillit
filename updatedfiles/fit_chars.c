#include "fillit.h"

int fit_char(char *bitmap_str, char *square_str, int size)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (bitmap_str[i])
	{
		if (bitmap_str[i]=='1' && (square_str[i+size]=='1' || square_str[i-size]
					=='1' || square_str[i+1]=='1' || square_str[i-1]=='1'))
			flag = 1;//it is in contact with the square's pieces
		if (square_str[i] == '1' && bitmap_str[i] == '1')
			return 0;//conflict
		i++;
	}
	if (flag)
		return 1;
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		ft_putnbr(fit_char(argv[1], argv[2], ft_atoi(argv[3])));
	ft_putchar('\n');
	return (0);
}
