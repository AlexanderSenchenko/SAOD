#include <stdio.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void HeapSort(int mass[], int n){
	int b = 0, i, m = n;
	while (b == 0){
		b = 1;
		for (i = m / 2; i >= 0; i--){
			if(mass[i] < mass[2 * i + 1] && 2 * i + 1 < m){
				swap(&mass[i], &mass[2 * i + 1]);
			}
			if(mass[i] < mass[2 * i + 2] && 2 * i + 2 < m){
				swap(&mass[i], &mass[2 * i + 2]);
			}
		}
		swap(&mass[0], &mass[m - 1]);
		m--;
		if (m > 0){
			b = 0;
		}
	}
}

int main()
{
	double t;
	FILE *A;
	int n, i;

	A = fopen("Random number.txt", "r");
	fscanf(A, "%d", &n);

	int mass[n];

	for (i = 0; i < n; i++){
		fscanf(A, "%d", &mass[i]);
	}
	fclose(A);

	t = wtime();
	HeapSort(mass, n);
	t = wtime() - t;

	for (i = 0; i < n; i++){
		printf("%d ", mass[i]);
	}
	printf("\n");
	printf("Elapsed time: %.6f sec.\n", t);

	return 0;
}
