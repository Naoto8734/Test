#include <stdio.h>

int main(void){
	char *p;
	char *msg = "C Programming";

	//文字列の終端を示す\0を見つけるまで繰り返す。
	for(p=msg; *p!='\0'; p++){
		putchar(*p);	//1文字ずつ出力
	}

	return 0;
}
