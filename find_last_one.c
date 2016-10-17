int find_last_one(unsigned short bitmap)
{
	return 	(bitmap ^ (bitmap & (bitmap - 1)));
}
