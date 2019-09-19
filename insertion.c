
#include <stdio.h>

int insbeg(int ar[], int n)
{
        int i, value;
        printf("enter the element to inserted:");
        scanf("%d", &value);
        for (i = 1; i >=0; i--)
        {
                ar[i + 1] = ar[i];
        }
        ar[0] = value;
}
int inspos(int a[], int n)
{
        int value, pos, i;

        printf("enter the value to be inserted\n");
        scanf("%d", &value);
        printf("enter the positon the value to be insertd\n");
        scanf("%d", &pos);
        for (i = n; i > pos - 1; i--)
        {
                a[i] = a[i - 1];
        }
        a[pos] = value;
}

void main()
{
        int a[50], i, n, ch;
        printf("enter the array size:");
        scanf("%d", &n);
        printf("enter the array elements:\n");
        for (i = 0; i < n; i++)
        {
                scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++)
        {
                printf("%d\t", a[i]);
        }
        printf("\n-----------Menu------------- \n1.insert at begining\n2.insert at position\n:");
        printf("enter the choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
                insbeg(a, n);
                printf("array after insertion is\n");
                for (i = 0; i < n + 1; i++)
                {
                        printf("%d\t", a[i]);
                }
                break;
        case 2:
                inspos(a, n);
                printf("array after insertion is \n");
                for (i = 0; i < n + 1; i++)
                {
                        printf("%d\t", a[i]);
                }
                break;

        default:
                printf("invalid choice");
                break;
        }
}
