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

void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i=n-1; i>=0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	FILE *A;
	double t;
	int n, i;

	A = fopen("Random number.txt", "r");	
	fscanf(A, "%d", &n);
	int arr[n];
	for(i = 0; i < n; i++){
		fscanf(A, "%d", &arr[i]);
	}
	fclose(A);

	t = wtime();

	heapSort(arr, n);
	
	t = wtime() - t;

	printf("Heap Sort: %.6f sec.\n", t);

	return 0;
}

