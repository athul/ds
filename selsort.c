#include <stdio.h>
int selsort(int a[], int n);
void main()
{
	int n, i, a[50];
	printf("Enter the Size of The Array:\n");
	scanf("%d", &n);
	printf("Enter the Elements");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	selsort(a, n);
	printf("The Sorted Array is :\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}
int selsort(int a[50], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[i];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}