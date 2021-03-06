#include <stdio.h>
#include <stdlib.h>

struct CELL {
	struct CELL *next;
	int value;
};

void set_cell(struct CELL *data, int val){
	struct CELL *temp;
	temp = malloc(sizeof(struct CELL));

	if(temp == NULL){
		printf("Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	while(data->next!=NULL){
		data = data->next;
	}

	temp->next = data->next;
	temp->value = val;
	data->next = temp;
}

void print_cell(struct CELL *data){
	struct CELL *p;

	for(p=data->next; p!=NULL; p=p->next){
		printf("value=%d\n", p->value);
	}
}

int main (void){
	struct CELL data;
	data.next = NULL;
	data.value = 0;
	int value;
	FILE *fp;

	if ((fp=fopen("data1.dat","r")) == NULL){
		printf("File not found. ---data1.dat\n");
		exit(EXIT_FAILURE);
	}
	
	while(fscanf(fp, "%d", &value) != EOF){
		set_cell(&data,value);
	}

	print_cell(&data);
	fclose(fp);

	return EXIT_SUCCESS;
}
