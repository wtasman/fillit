//build function pointer array 
//loop through all 19 and while it equals -1 keep looping until the end
//if it breaks return the return of the function at i
//

int is_square(unsigned short tet);
int is_vertical_straight(unsigned short tet);
int is_horizontal_straight(unsigned short tet);
int is_normal_t(unsigned short tet);
int is_left_t(unsigned short tet);
int is_right_t(unsigned short tet);
int is_upside_down_t(unsigned short tet);
int is_normal_j(unsigned short tet);
int is_downward_j(unsigned short tet);
int is_upside_down_j(unsigned short tet);
int is_upward_j(unsigned short tet);
int is_normal_z(unsigned short tet);
int is_rotated_z(unsigned short tet);
int is_normal_s(unsigned short tet);
int is_rotated_s(unsigned short tet);
int is_normal_l(unsigned short tet);
int is_upward_l(unsigned short tet);
int is_upside_down_l(unsigned short tet);
int is_downward_l(unsigned short tet);



int (*p[19]) (unsigned short);

int classify(unsigned short value)
{
	int i;

	i = 0;
	p[0] = is_square;
	p[1] = is_vertical_straight;
	p[2] = is_horizontal_straight;
	p[3] = is_normal_t;
	p[4] = is_left_t;
	p[5] = is_right_t;
	p[6] = is_upside_down_t;
	p[7] = is_normal_j;
	p[8] = is_downward_j;
	p[9] = is_upside_down_j;
	p[10] = is_upward_j;
	p[11] = is_normal_z;
	p[12] = is_rotated_z;
	p[13] = is_normal_s;
	p[14] = is_rotated_s;
	p[15] = is_normal_l;
	p[16] = is_upward_l;
	p[17] = is_upside_down_l;
	p[18] = is_downward_l;

	while(((*p[i]) (value))==-1)
		i++;
	return ((*p[i]) (value));

}
