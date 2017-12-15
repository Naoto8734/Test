#include <stdio.h>
/*ポインタのテスト2*/
int main (void){
	int base = 'a';
	int i;
	int *p = &base;
	
	for (i=0; i<5; i++){
		printf("p = %p\n",p+i);
	}
	
	printf("size = %d\n",sizeof(int));
	return 0;
}
