#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap( int *xp, int *yp ){
	int p = *xp;
	*xp = *yp;
	*yp = p;
}

void bubbleSort( int size, int data[] ){
	int i, j;
	int count=0;
	for (i=0; i<size-1; i++){
		for (j=0; j<size-i-1; j++){
			if (data[j] > data[j+1]){
				swap(&data[j], &data[j+1]);
				count++;
			}
		}
	}
	//printf("swap count = %d\n",count);
	printf("%d,", count);
}

void printData( int size, int data[] ){
	int i;
	for ( i = 0; i < size; i++ )
		printf( "%d ", data[i] );
	printf( "\n" );
}

void printPlot( int size, int data[] ){
	int i, j;
	for ( i = 0; i < size; i++ ) {
		printf( "%5d:", i );
		for ( j = 0; j < data[i]; j++ ) {
			printf( "%c", '*' );
		}
	printf( "\n" );
	}
}

void process(int size){
	//int size = 20;
	int *datap;
	int i;
	clock_t c1, c2;

	/* データ領域の確保 */
	if ( NULL == ( datap = ( int * ) calloc( size, sizeof( int ) ) ) ) {
		fprintf( stderr,"ERROR:メモリ領域が確保できませんでした．\n" );
		//return EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}

	/* データを 1, 2, 3, ..., size  で初期化する */
	/*for ( i = 0; i < size; ++i ) {
		datap[i] = i + 1;
	}*/
	
	/* データを size, size-1, size-2, ..., 0  で初期化する */
	for ( i = 0; i < size; ++i ) {
		datap[i] = size-i;
	}

	/* データをsize回，ランダムに要素を入れ替える */
	//for ( i = 0; i < size; ++i ) {
		//swap( &datap[rand(  ) % size], &datap[rand(  ) % size] );
	//}

	/* ソート前のデータを出力する */
	#ifndef TIME
	printf( "ソート前のデータ:\n" );
	printData( size, datap );
	printPlot( size, datap );
	#endif

	/* ソート */
	printf("%d,",size);
	c1 = clock(  );
	bubbleSort( size, datap );
	c2 = clock(  );
	//printf( "sort time = %f [s]\n",( double ) ( c2 - c1 ) / CLOCKS_PER_SEC );
	printf( "%f\n",( double ) ( c2 - c1 ) / CLOCKS_PER_SEC );
	
	/* ソート後のデータを出力する */
	#ifndef TIME
	printf( "ソート後のデータ:\n" );
	printData( size, datap );
	printPlot( size, datap );
	#endif

	/* メモリ領域を解放する */
	free( datap );
}

int main(void){
	srand( ( unsigned ) time( NULL ) );
	int j;
	for (j=5000;j<=30000;j+=1000){
		process(j);
	}
	//process(20);
	return EXIT_SUCCESS;
}
