#include <stdio.h>

int is_Lacomij_kusochek (int one_part, int second_part);

struct BigKrasavchik_t 
{
	int size_left_hand;
	int size_right_hand;
};
int main ()
{
	struct BigKrasavchik_t bigKrasavchik;
	
	bigKrasavchik.size_left_hand =135;
	bigKrasavchik.size_right_hand = 115;

	return is_Lacomij_kusochek (bigKrasavchik.size_left_hand, bigKrasavchik.size_right_hand);
}


int is_Lacomij_kusochek (int one_part, int second_part)
{
	 return one_part+second_part;
}
