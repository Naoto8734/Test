#include <stdio.h>
#include <stdlib.h>

int main(void){
	int val;
	int sum = 0;
	int cnt = 0;
	char FileName[FILENAME_MAX];
	FILE *fp;

	printf("Input file name >>>");
	scanf("%s", FileName);
	if( (fp = fopen(FileName, "r")) == NULL){
		printf("Filure to find file ---%s\n", FileName);
		exit(EXIT_FAILURE);
	}

	cnt = 0;
	while(fscanf(fp, "%d", &val) != EOF){
		sum += val;
		cnt++;
	}

	if(cnt>0){
		printf("SUM=%d AVE=%g\n", sum, (double)sum/cnt);
	}

	return EXIT_SUCCESS;
}
