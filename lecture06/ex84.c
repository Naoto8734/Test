#include <stdio.h>
#include <math.h>

#define MAX_SEAT 5

int main(void){
	struct seat_position{
		int no;
		double x;
		double y;
	}seat[MAX_SEAT];

	double x_dis, y_dis;
	double dis;
	double max_dis = 0.0;

	int max_dis_seat[2];
	int i, j;

	printf("Please input No, x, y.");
	for (i=0; i<MAX_SEAT; i++){
		scanf("%d %1f %1f", &seat[i].no, &(seat[i].x), &(seat[i].y));
	}

	for (i=0; i<MAX_SEAT-1; i++){
		for (j=0; j<MAX_SEAT; j++){
			x_dis = seat[i].x - seat[j].x;
			y_dis = seat[i].y - seat[j].y;
			dis = sqrt(x_dis*x_dis + y_dis*y_dis);
			if(max_dis < dis){
				max_dis = dis;
				max_dis_seat[0] = seat[i].no;
				max_dis_seat[1] = seat[j].no;
			}
		}
	}

	printf("最も離れた座席は%dと%dです。（距離：%f）\n", max_dis_seat[0], max_dis_seat[1], max_dis);

	return 0;
}
