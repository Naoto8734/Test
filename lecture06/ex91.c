#include <stdio.h>

int main(void){
	struct tag{
		int x;
		double y;
	}sample;

	struct tag *p;

	p = &sample;
	p->x = 10;
	p->y = 20.0;

	printf("x = %d, y=%e\n", p->x, p->y);


	return 0;
}
