#include <stdio.h>
#include "posn.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name
//ERROR_I_have_NOT_yet_completed_the_INTEGRITY_statement
// Name:
// login ID:



void twice_the_difference(struct posn *p1, struct posn *p2) {
	// WRITE CODE HERE
	struct posn temp = {.x = p1->x - p2->x, .y = p1->y - p2->y };
  //STACK FRAME SHOWN AT THIS POINT (the end of this function)
}

////DO NOT CHANGE THIS FUNCTION
//int main(void) {
//	struct posn first_posn = {10,5};
//	struct posn second_posn = {3,2};
//	twice_the_difference(&first_posn, &second_posn);
//}
