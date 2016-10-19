is_fit(char **tet_array, char **square_str, int size)
{
	if(*tet_array)//if we havent reached the last tetrimino
	{
		if fit_char(fix_offset(*tet_array, size), square_str, size);
		{
			//set tet_array into square_str as a potential solution
			*square_str++ = *tet_array++;
			is_fit(tet_array, square_str, size);
			//since we need the double pointer to keep track through recursions each call to fit_char will be dereferenced, 
			//then the double pointer will be incremented and passed to the next is_fit call
			//CASE OF SUCCESS.
			return square_str;
		}
		else
			if((*tet_array = shift(fix_offset(*tet_array, size))))
				is_fit(tet_array, square_str, size);
			else
				return 0;
	}
	return 0;
}
