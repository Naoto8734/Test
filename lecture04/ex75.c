#include <stdio.h>

void str_copy(char [], char []);

int main(void){
	char src[] = "SRC";
	char dst[4];

	str_copy(dst, src);
	printf("%s\n", dst);
	return 0;
}

//srcをdstにコピーする関数。
void str_copy(char dst[], char src[]){
	int i;
	for(i=0; src[i]!='\0'; i++){
		dst[i] = src[i];
	}
	dst[i] = '\0';
}
