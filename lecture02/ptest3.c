#include <stdio.h>
/*ポインタの演算のテスト 演算子による違い*/
int main (void){
	int base = -4;
	int i;
	int *p = &base;
	
	for (i=0; i<5; i++){
		printf("p = %p\n",p);
		p += 3;
	}
	
	printf("size = %d\n",sizeof(int));
	return 0;
}
