#include <stdio.h>
#include <stdlib.h>

struct CELL {
	struct CELL *next;
	int value;
};

void set_cell(struct CELL *data, int val){
	struct CELL *temp, *p;
	temp = malloc(sizeof(struct CELL));

if(temp == NULL){
		printf("Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	for(p=data; p->next!=NULL; p=p->next);

	temp->next = p->next;
	temp->value = val;
	p->next = temp;
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

	set_cell(&data,1);
	set_cell(&data,2);
	set_cell(&data,5);
	set_cell(&data,10);
	set_cell(&data,20);
	set_cell(&data,100);

	print_cell(&data);

	return EXIT_SUCCESS;
}
