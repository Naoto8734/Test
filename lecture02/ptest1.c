#include <stdio.h>
/*ポインタのテスト1*/
int main (void){
	char base = 'a';
	int i;
	char *p = &base;
	
	for (i=0; i<5; i++){
		printf("p = %p\n",p+i);
	}
	
	printf("size = %d\n",sizeof(char));
	return 0;
}
