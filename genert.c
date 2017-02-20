#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int a, char *argv[]){
	FILE *A;
	srand(time(0));
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int mass[n];

	for(int i = 0; i < n; i++){
		mass[i] = rand() % k;
	}
	A = fopen("Random number.txt", "w");

	fprintf(A, "%d\n", n);
	for(int i = 0; i < n; i++){
		fprintf(A, "%d ", mass[i]);;
	}
	fprintf(A, "\n");
	fprintf(A, "%d\n", k);

	fclose(A);

	return 0;
}
