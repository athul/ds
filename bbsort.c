#include <stdio.h>
int bbsort(int a[], int size);
int main()
{
	int i, n, a[50], sort;
	printf("Enter Size of the Array\n");
	scanf("%d", &n);
	printf("Enter the Array:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort = bbsort(a, n);
	printf("Sorted array is \n");
	for (i = 0; i < n; i++)
		printf("\t%d", a[i]);
}
int bbsort(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
		for (j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
}