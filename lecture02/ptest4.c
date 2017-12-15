#include <stdio.h>
int main (void){
	int a[10];
	int *a1, *a2, *a3;
	a1 = a;
	a2 = &a[5];
	a3 = a1 + 7;
	
	printf("a2 - a1 = %p\n", a2- a1);
	printf("a3 - a1 = %p\n", a3- a1);
	printf("a3 - a2 = %p\n", a3- a2);
	
	return 0;
}
