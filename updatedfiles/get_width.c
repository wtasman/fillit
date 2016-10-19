int getwidth(unsigned short bitmap)
{
	if (!(bitmap ^ 52224) || !(bitmap ^ 35968) || !(bitmap ^ 19520) || !(bitmap ^ 17600) || !(bitmap ^ 51328) || !(bitmap ^ 19584) || !(bitmap ^ 35904) || !(bitmap ^ 35008) || !(bitmap ^ 50240))
		return 2;//square//left t //right t //normal j // upside down j // rotated z // rotated s // normal l // upside down l
	if (!(bitmap ^ 34952))
		return 1;//vertical straight
	if (!(bitmap ^ 61440))
		return 4;//horizontal straight
	if (!(bitmap ^ 58368) || !(bitmap ^ 19968) || !(bitmap ^ 57856) || !(bitmap ^ 36352) || !(bitmap ^ 50688) || !(bitmap ^ 27648) || !(bitmap ^ 11776) || !(bitmap ^ 59392)
		return 3;//normal t // upside down //downward j // upward j // normal z // normal s // upward l // downward l
	return 0;
}

