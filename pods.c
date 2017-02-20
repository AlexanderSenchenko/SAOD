#include <stdio.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void sort(int arr[], int n, int k){
	int C[k];
	for (int i = 0; i < k ; i++){
		C[i] = 0;
	}

	for (int i = 0; i < n ; i++){
		C[arr[i]] = C[arr[i]] + 1;
	}
	int b = 0;
	for (int j = 0; j < k; j++){
		for (int i = 0; i < C[j]; i++){
			arr[b] = j;
			b++;
		}
	}
}

int main(void){
	double t;
	FILE *A;

	A = fopen("Random number.txt", "r");
	int n, k;
	fscanf(A, "%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++){
		fscanf(A, "%d", &arr[i]);
	}
	fscanf(A, "%d", &k);
	fclose(A);

	t = wtime();
	sort(arr, n, k);
	t = wtime() - t;

	for (int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("Elapsed time: %.6f sec.\n", t);
}
