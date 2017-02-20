#include <stdio.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void swap (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int main()
{
	FILE *A;
	double t;
  int n, i, sh = 0, b = 0;
	A = fopen("Random number.txt", "r");
  fscanf(A, "%d", &n);
	int a[n];
  for (i = 0; i < n; ++i) {
    fscanf(A, "%d", &a[i]);
	}
	fclose(A);

t = wtime();
  while (1)
  {
    b = 0;
    for (i = 0; i < n; ++i)
    {
      if (i*2 + 2 + sh < n)
      {
        if (a[i+sh] > a[i*2 + 1 + sh] || a[i + sh] > a[i*2 + 2 + sh])
	{
	  if (a[i*2+1+sh] < a[i*2+2+sh])
	  {
	    swap (&a[i+sh], &a[i*2+1+sh]);
	    b = 1;
	  }
	  else if (a[i*2+2+sh] < a[i*2+1+sh])
	  {
	    swap (&a[i+sh],&a[i*2+2+sh]);
	    b = 1;
	  }
	}
      }
      else if (i * 2 + 1 + sh < n)
      {
        if (a[i+sh] > a[i*2+1+sh])
	{
	  swap (&a[i+sh], &a[i*2+1+sh]);
	  b=1;
	}
      }
    }
    if (!b) sh++;
    if (sh+2==n)
      break;
  }
t = wtime() - t;

  for (i = 0; i < n; ++i){
    printf ("%i%c", a[i], (i!=n-1)?' ':'\n');
	}
printf("Elapsed time: %.6f sec.\n", t);
  return 0;
}
