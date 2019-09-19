#include <stdio.h>
void bsearch(int b[10], int n, int s)
{
	int l = 0, m, h = n, f = 0;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (b[m] == s)
		{
			printf("\n Succesful Search!!!!");
			printf("\n Element present at index  %d\n", m + 1);
			f = 1;
			break;
		}
		else if (b[m] < s)
			h = m - 1;
		else
			l = m + 1;
	}
	if (f == 0)
	{
		printf("Unsuccessful Search");
	}
}
void main()
{
	int i, m, a[10], p;
	printf("Enter Size of the Array\n");
	scanf("%d", &m);
	printf("\n Enter Elements\n");
	for (i = 0; i < m; i++)
		scanf("%d", &a[i]);
	printf("Enter the element to be searched\t");
	scanf("%d", &p);
	bsearch(a, m, p);
}
