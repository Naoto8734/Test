#include <stdio.h>
#include <stdlib.h>

int main(void){
	int val;
	int sum = 0;
	int cnt = 0;
	FILE *fpin, *fpout;

	if ( (fpin=fopen("exdata1.dat","r")) == NULL){
		printf("File not found. --- exdata1.dat\n");
		exit(EXIT_FAILURE);
	}

	if ( (fpout=fopen("out.dat","w")) == NULL ){
		fclose(fpin);
		printf("File not made. --- out.dat\n");
		exit(EXIT_FAILURE);
	}

	while( fscanf(fpin,"%d",&val) != EOF){
		fprintf(fpout,"Input data >>> %d\n", val);
		sum += val;
		++cnt;
	}

	if(cnt>0){
		printf("SUM=%d, AVE=%g\n", sum, (double)sum/cnt);
	}

	fclose(fpin);
	fclose(fpout);

	return EXIT_SUCCESS;
}
