nt is_right_t(unsigned short tet)struct subtypes
{
	char *name;
	int count;
};

int is_square(unsigned short tet)
{
	if (!(tet ^ 52224) || !(tet ^ 26112) || !(tet ^ 13056) || !(tet ^ 3264) \
			|| !(tet ^ 1632) || !(tet ^ 816) || !(tet ^ 204) || !(tet ^ 102) || !(tet ^ 51))
		return 0;
	else 
		return -1;
}

int is_vertical_straight(unsigned short tet)
{
	if(!(tet ^ 34952) || !(tet ^ 17476) || !(tet ^ 8738) || !(tet ^ 4369))
		return 1;
	else
		return -1;
}

int is_horizontal_straight(unsigned short tet)
{
	if(!(tet ^ 61440) || !(tet ^ 3840) || !(tet ^ 240) || !(tet ^ 15))
		return 2;
	else
		return -1;
}

int is_normal_t(unsigned short tet)
{
	if (!(tet ^ 58368) || !(tet ^ 29184) || !(tet ^ 3648) || !(tet ^ 1824) || !(tet ^ 228) || !(tet ^ 114))
		return 3;
	else
		return -1;
}
int is_left_t(unsigned short tet)
{
	if (!(tet ^ 35968) || !(tet ^ 17984) || !(tet ^ 8992) || !(tet ^ 2248) || !(tet ^ 1124) || !(tet ^ 562))
		return 4;
	else
		return -1;
}

int is_right_t(unsigned short tet)
{
	if (!(tet ^ 19520) || !(tet ^ 9760) || !(tet ^ 4880) || !(tet ^ 1220) || !(tet ^ 610) || !(tet ^ 305))
		return 5;
	else
		return -1;
}

int is_upside_down_t(unsigned short tet)
{
	if (!(tet ^ 19968) || !(tet ^ 9984) || !(tet ^ 1248) || !(tet ^ 624) || !(tet ^ 78) || !(tet ^ 39))
		return 6;
	else
		return -1;
}

int is_normal_j(unsigned short tet)
{
	if (!(tet ^ 17600) || !(tet ^ 8800) || !(tet ^ 4400) || !(tet ^ 1100) || !(tet ^ 550) || !(tet ^ 275))
		return 7;
	else
		return -1;
}

int is_downward_j(unsigned short tet)
{
	if (!(tet ^ 57856) || !(tet ^ 28928) || !(tet ^ 3616) || !(tet ^ 1808) || !(tet ^ 226) || !(tet ^ 113))
		return 8;
	else
		return -1;
}

int is_upside_down_j(unsigned short tet)
{
	if (!(tet ^ 51328) || !(tet ^ 25664) || !(tet ^ 12832) || !(tet ^ 3208) || !(tet ^ 1604) || !(tet ^ 802))
		return 9;
	else
		return -1;
}

int is_upward_j(unsigned short tet)
{
	if (!(tet ^ 36352) || !(tet ^ 18176) || !(tet ^ 2272) || !(tet ^ 1136) || !(tet ^ 142) || !(tet ^ 71)) 
		return 10;
	else
		return -1;
}

int is_normal_z(unsigned short tet)
{
	if (!(tet ^ 50688) || !(tet ^ 25344) || !(tet ^ 3168) || !(tet ^ 1584) || !(tet ^ 198) || !(tet ^ 99))
		return 11;
	else
		return -1;
}

int is_rotated_z(unsigned short tet)
{
	if (!(tet ^ 19584) || !(tet ^ 9792) || !(tet ^ 4896) || !(tet ^ 1224) || !(tet ^ 612) || !(tet ^ 306))
		return 12;
	else
		return -1;
}

int is_normal_s(unsigned short tet)
{
	if (!(tet ^ 27648) || !(tet ^ 13824) || !(tet ^ 1728) || !(tet ^ 864) || !(tet ^ 108) || !(tet ^ 54))
		return 13;
	else
		return -1;
}
int is_rotated_s(unsigned short tet)
{
	if (!(tet ^ 35904) || !(tet ^ 17952) || !(tet ^ 8976) || !(tet ^ 2244) || !(tet ^ 1122) || !(tet ^ 561))
			return 14;
	else
		return -1;
}

int is_normal_l(unsigned short tet)
{
	if (!(tet ^ 35008) || !(tet ^ 17504) || !(tet ^ 8752) || !(tet ^ 2188) || !(tet ^ 1094) || !(tet ^ 547))
		return 15;
	else
		return -1;
}

int is_upward_l(unsigned short tet)
{
	if (!(tet ^ 11776) || !(tet ^ 5888) || !(tet ^ 736) || !(tet ^ 368) || !(tet ^ 46) || !(tet ^ 23))
		return 16;
	else
		return -1;
}

int is_upside_down_l(unsigned short tet)
{
	if (!(tet ^ 50240) || !(tet ^ 25120) || !(tet ^ 12560) || !(tet ^ 3140) || !(tet ^ 1570) || !(tet ^ 785))
		return 17;
	else
		return -1;
}

int is_downward_l(unsigned short tet)
{
	if (!(tet ^ 59392) || !(tet ^ 29696) || !(tet ^ 3712) || !(tet ^ 1856) || !(tet ^ 232) || !(tet ^ 116))
		return 18;
	else
		return -1;
}

