#include <stdio.h>
#include <string.h>

struct stationary_stock {
	int quantity;	/*数量*/
	char name[20];	/*名前*/
};

int main(void) {
	int i;
	struct stationary_stock tray[5];

	strcpy(tray[0].name, "消しゴム");
	strcpy(tray[1].name, "クリップ");
	strcpy(tray[2].name, "のり");
	strcpy(tray[3].name, "えんぴつ");
	strcpy(tray[4].name, "付箋紙");

	tray[0].quantity = 15;
	tray[1].quantity = 200;
	tray[2].quantity = 18;
	tray[3].quantity = 55;
	tray[4].quantity = 30;

	printf("文房具のストック\n");

	for(i=0; i<5; i++){
		printf("\t%s", tray[i].name);  
		printf("\t%d\n", tray[i].quantity);
	}

	return 0;
}
