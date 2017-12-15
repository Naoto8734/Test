#include <stdio.h>
#include <string.h>

int main(void){
	struct roll {
		char name[32];
		int birth;
		int zip;
		char address[82];
		char tel[20];
	} my_data;

	strcpy( my_data.name, "Hinako");
	my_data.birth = 19890225;
	my_data.zip = 1234567;
	strcpy( my_data.address, "Yokohama-shi Kanagawa Pref.");
	strcpy( my_data.tel, "045-123-4567");
	printf("\nNAME         BIRTHDAY   ZIP     "
			"ADDRESS                        TEL\n");
	printf("%-10.10s%11.8d%10.7d %-30.30s %-12.12s\n",
			my_data.name, my_data.birth, my_data.zip, my_data.address, my_data.tel);
	return 0;
}
