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
	struct CELL data, *p;
	data.next = NULL;
	data.value = 0;
	int value;
	FILE *fp;

	if ((fp=fopen("data2.dat","r")) == NULL){
		printf("File not found. ---data2.dat\n");
		exit(EXIT_FAILURE);
	}

	while(fscanf(fp, "%d", &value) != EOF){
		for(p=&data; p->next!=NULL; p=p->next);
		set_cell(p,value);
	}

	printf("Before\n");
	print_cell(&data);

	printf("After\n");
	for (p=data.next; p!=NULL; p=p->next){
		if (p->value == 6){
			set_cell(p,5);
			break;
		}
	}
	print_cell(&data);
	fclose(fp);

	return EXIT_SUCCESS;
}
