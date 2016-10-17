int fit_bitmap(unsigned long long bitmap, unsigned long long potential_solution)
{
	if (bitmap ^ potential_solution)//this solution fits
	{
		if (find_last_one(bitmap) % size == 0 || find_first_one(bitmap) + get_width(bitmap) % size == 0)
		{
			if (((bitmap << 1) ^ potential_solution) || ((bitmap >> size) ^ potential_solution) || ((bitmap << size) ^ potential_solution))
				return 1;
		}
		else if (find_last_one(bitmap) -  get_width(bitmap) % size == 1 || find_first_one(bitmap % size == 1))
		{
			if (((bitmap >> 1) ^ potential_solution) || ((bitmap >> size) ^ potential_solution) || ((bitmap << size) ^ potential_solution))
				return 1;
		}
		else	
		{
			if (((bitmap >> 1) ^ potential_solution) || ((bitmap << 1) ^ potential_solution) || ((bitmap >> size) ^ potential_solution) || ((bitmap << size) ^ potential_solution))
				return 1;
		}
	}
	return 0;
}
