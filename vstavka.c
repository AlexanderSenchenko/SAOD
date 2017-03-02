#include <stdio.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{	
	double t;	
	FILE *A;
	int n, i, j, x;

	A = fopen("Random number.txt", "r");
	fscanf(A, "%d", &n);

	int mass[n];

	for(int i = 0; i < n; i++){
		fscanf(A, "%d", &mass[i]);
	}
	fclose(A);

	t = wtime();
	for (i = 1; i < n; i++){
    		x = mass[i];
    		for (j = i - 1; j >= 0; j--){
		        if (mass[j] < x){
            			break;
			}
			else{ 
       				mass[j + 1] = mass[j];
       				mass[j] = x;
			}    		
		}
	}
	t = wtime() - t;

	printf("Elapsed time: %.6f sec.\n", t);
	return 0;
}
