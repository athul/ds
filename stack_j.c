#include <stdio.h>
//#include<conio.h>
int a[50], top = -1;
void push()
{
    int element;
    printf(" Enter a value to be pushed:");
    scanf("%d", &element);
    top++;
    a[top] = element;
}
void pop()
{
    int del;
    if (top < 0)
    {
        printf("the stack is empty");
    }
    else
    {
        del = a[top];
        printf("the element %d is deleted from the stack:",a[top]);
        top -= 1;
    }
}
void status(){
    int i;
    for (i=top;i>=0;i++){
            printf("\n%d", a[i]);
    }
}
void main(){
    int choice,i;
    printf("Enter You Choices:\n");
    printf("1. PUSH\n2.POP\n3.Display\n4.EXIT\n");
    do
    {
        printf("Enter your Choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            push();
            break;
        }
        case 2:{
            push();
            break;
        }
        case 3:{
            status();
            break;
        }
        case 4:{
            break;
        }
        default:{
            printf("Enter a Valid Input Please");
            break;
        }
        }
    } while (choice!=4);
    
}