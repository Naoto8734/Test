#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	struct CELL *next;
	int value;
} CELL_t;

void set_cell(CELL_t *data, int val);
void print_cell(CELL_t *data);
void list_concatenate(CELL_t *data0, CELL_t *data1);

int main (void){
	int i, value;
	FILE *fp1, *fp2;

	//printf("DEBUG:連結リストdata1,data2の定義\n");
	CELL_t data1, data2;
	data1.next = NULL;
	data1.value = 0;
	data2.next = NULL;
	data2.value = 0;

	//printf("DEBUG:連結リストdata1にファイルから読み込み、セット\n");
	if ((fp1=fopen("data1.dat","r")) == NULL){
		printf("File not found. ---data1.dat\n");
		exit(EXIT_FAILURE);
	}
	while(EOF != fscanf(fp1, "%d", &value)){
		//printf("DEBUG:data1.dat value=%d\n",value);
		set_cell(&data1, value);
	}
	fclose(fp1);

	//printf("DEBUG:連結リストdata2にファイルから読み込み、セット\n");
	if ((fp2=fopen("data2.dat","r")) == NULL){
		printf("File not found. ---data2.dat\n");
		exit(EXIT_FAILURE);
	}
	while(EOF != fscanf(fp2, "%d", &value)){
		//printf("DEBUG:data2.dat value=%d\n",value);
		set_cell(&data2, value);
	}
	fclose(fp2);

	//printf("DEBUG:連結リストdata1の後に連結リストdata2を結合する\n");
	list_concatenate(&data1,&data2);
	print_cell(&data1);

	return EXIT_SUCCESS;
}


void set_cell(CELL_t *data, int val){
	CELL_t *temp;
	temp = malloc(sizeof(CELL_t));

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

void print_cell(CELL_t *data){
	CELL_t *p;

	for(p=data->next; p!=NULL; p=p->next){
		printf("value=%d\n", p->value);
	}
}

void list_concatenate(CELL_t *data0, CELL_t *data1){
	CELL_t *p, *prev;
	
	if (data0->next != NULL){
		if (data1->next != NULL){
			for (p = data0->next; p!=NULL; p=p->next){
				prev=p;
			}
			prev->next = data1->next;
		}
	}else{
		data0->next = data1->next;
	}
}
