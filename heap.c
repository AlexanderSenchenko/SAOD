#include <stdio.h>
#include <stdlib.h>
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

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */

// Driver program
int main()
{
	FILE *A;
	int n, i;
	A = fopen("Random number.txt", "r");
	fscanf(A, "%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++){
		fscanf(A, "%d", &arr[i]);
	}
	fclose(A);
	double t;

	t = wtime();

	heapSort(arr, n);
	
	t = wtime() - t;

	for(i=0; i < n; i++){
		printf("%3d ", arr[i]);
	}
	printf("\n");
	printf("Heap Sort: %.6f sec.\n", t);
	FILE *B;
	B = fopen("Results.txt", "a");

	fprintf(B, "Heap Sort: %.6f sec.\n", t);

	fclose(B);

}

