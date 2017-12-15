#include <stdio.h>

static char top[] = "私の好きなスポーツは";
static char tail[] = "です。";

static char stmnt[100];

void str_copy(char [], char []);
void str_cat(char [], char []);

int main(void){
	str_copy(stmnt, top);
	printf("%s\n", stmnt);

	str_cat(stmnt, "水泳");
	printf("%s\n", stmnt);

	str_cat(stmnt, "とランニング");
	printf("%s\n", stmnt);

	str_cat(stmnt, tail);
	printf("%s\n", stmnt);

	return 0;
}


void str_copy(char dst[], char src[]){
	int i;

	for (i=0; src[i]!="\0"; i++){
		dst[i] = src[i];
	}
	dst[i] = "\0";
	printf("copy OK.");
}


void str_cat(char dst[], char src[]){
	int i,j;

	for (i=0; dst[i]!="\0"; i++);

	for (j=0; src[j]!="\0"; i++,j++){
		dst[i] = src[j];
	}
	dst[i] = "\0";
}
