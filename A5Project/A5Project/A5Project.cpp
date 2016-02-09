#include "stdafx.h"
struct posn {
	int x;
	int y;
};
void foo(int *p1,int *p2){
	p1 = p2;
	*p1 = 25;
	*p2 = 35;
	// point A 
}
void swap(struct posn *p1, struct posn *p2){
	p1->x = p2->x;
	p2->x = p1->x;
	p2->y = p1->y;
	p1->y = p2->y;
	//point B
}
int _tmain(int argc, _TCHAR* argv[]){
	int x = 10;
	int y = 20;
	foo(&x, &y);
	struct posn p1 = { 42, 24 };
	struct posn p2 = { 21, 12 };
	swap(&p1, &p2);
	//point C
}
