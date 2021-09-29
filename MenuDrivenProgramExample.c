#include <stdio.h>
#include <stdlib.h>

void read_and_store(int *A, int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
}

long long int sum(int *A, int n)
{
	long long int s = 0;

	for(int i = 0; i < n; i++)
	{
		s += A[i];
	}

	return s;
}

void print(int *A, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");
}

int search(int *A, int n, int s)
{
	for(int i = 0; i < n; i++)
	{
		if(A[i] == s)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int n = 0, s, i, *A;
	char ch;

	while (1)
	{
		scanf("%c", &ch);

		switch (ch)
		{
			case 'r':	scanf("%d", &n);
						A = (int*) malloc(n * sizeof(int));
						read_and_store(A, n);
						break;

			case 's':	printf("%lld\n", sum(A, n));
						break;

			case 'f':	scanf("%d", &s);
						printf("%d\n", search(A, n, s));
						break;

			case 'k':	scanf("%d", &i);
						printf("%d\n", sum(A, i));
						break;

			case 'p':	print(A, n);
						break;

			case 't': 	return 1;
		}
	}

	return 0;
}
