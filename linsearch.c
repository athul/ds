#include<stdio.h>
void main()
{
int i,n,a[10],p,f=0;
printf("Enter array size\t");
scanf("%d",&n);
printf("\nEnter elements into array\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
printf("Enter element to be searched\t");
scanf("%d",&p);
for(i=0;i<n;i++)
{
	if(p==a[i])
	{
		i++;
		printf("\n Succesful Search!!!");
		printf("\n Element present at index %d \n",i);
		f=1;
		break ;
	}
}
if(f==0)
printf("Unsuccessful Search");
}
