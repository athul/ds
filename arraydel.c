#include <stdio.h>
int delpos(int a[], int n);
int main()
{
    int i, n, a[1000], choice;
    printf("enter array size\n");
    scanf("%d", &n);
    printf("enter elements into the array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    delpos(a, n);
    printf("array after deletion is\n");
    for (i = 0; i < n - 1; i++)
        printf("%d\t", a[i]);
}
int delpos(int a[], int n)
{
    int i, pos;
    printf("enter the position of the element to be deleted\n");
    scanf("%d", &pos);
    for (i = pos; i < n - 1; i++)
        ;
    a[i] = a[i + 1];
}
