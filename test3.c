#include<stdio.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void build_Heap(int [],int);
void HeapSort(int H[],int n);
 
int main()
{
	FILE *A;
	double t;
    int n,i;

    	A = fopen("Random number.txt", "r");
    	fscanf(A, "%d", &n);
	int arr[n];

    for(i=1;i<=n;i++){
        fscanf(A, "%d", &arr[i]);
	}

	fclose(A);

	t = wtime();
    HeapSort(arr,n);
	t = wtime() - t;


    for(i=1;i<=n;i++)
    {
        printf("\t%d",arr[i]);
    }
	printf("Elapsed time: %.6f sec.\n", t);
    return 0;
}
 
void build_Heap(int H[],int n)
{
    int i,j,k,v,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=0;
        while(heap==0 && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(H[j]<H[j+1])
                    j++;
            }
            if(v>=H[j])
                heap=1;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
}
 
void HeapSort(int H[],int n)
{
    int t,i;
    for(i=n;i>=1;i--)
    {
        build_Heap(H,i);
        t=H[1];
        H[1]=H[i];
        H[i]=t;
    }
}
