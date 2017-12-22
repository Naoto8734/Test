#include <stdio.h>
#include <stdlib.h>

int main (void){
	FILE *fp;

	if ( (fp=fopen("sample.dat","a")) == NULL){
		printf("File not found. --- sample.dat\n");
		exit(EXIT_FAILURE);
	}

	printf("debug\n");

	fprintf(fp,"But, if you do your best,\n");
	fprintf(fp,"you will manage.\n");

	fclose(fp);

	return EXIT_SUCCESS;
}
