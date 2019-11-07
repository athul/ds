#include <stdio.h>
#include <stdlib.h>
int create();
int display();
int insertbeg();
int insertend();
int insertpos();
int deletebeg();
int deleteend();
int deletepos();
struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;
int main()
{
    int choice;
    while (1)
    {
        printf("\n-------------------------------------");
        printf("\n1.create \n2.display \n3.insert at begin \n4.insert at end \n5.insert at position\n6.delete at begin \n7.delete at end \n8.delete at position\n9.Exit\n");
        printf("enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insertbeg();
            break;
        case 4:
            insertend();
            break;
        case 5:
            insertpos();
            break;
        case 6:
            deletebeg();
            break;
        case 7:
            deleteend();
            break;
        case 8:
            deletepos();
            break;
        case 9:
            exit(0);
        default:
            printf("invalid option");
            exit(0);
        }
    }
    return 0;
}
int create()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("out of memory");
        exit(0);
    }
    printf("enter data value:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
int display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("list is empty:");
        return 0;
    }
    else
    {
        ptr = start;
        printf("the list elements are:");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->info);
            ptr = ptr->next;
        }
    }
}
int insertbeg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("out of memory");
        return 0;
    }
    printf("enter the data value for the node:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}
int insertend()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("out of memory");
        return 0;
    }
    printf("enter data value for node:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
int insertpos()
{
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("out of memory");
        return 0;
    }
    printf("enter position for new node to be inserted:");
    scanf("%d", &pos);
    printf("enter the data value of new node:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (pos == 0)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        for (i = 1, ptr = start; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("position not found");
                return 0;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
int deletebeg()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("deletion is not possible");
        return 0;
    }
    temp->next = NULL;
    if (start->next == NULL)
    {
        temp = start;
        start = NULL;
        printf("deleted element is %d", temp->info);
        free(temp);
    }
    else
    {
        temp = start;
        start = start->next;
        printf("deleted element is %d", temp->info);
        free(temp);
    }
}
int deleteend()
{
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("deletion not possible");
        return 0;
    }
    if (start->next == NULL)
    {
        temp = start;
        start = NULL;
        printf("deleted element is %d", temp->info);
        free(temp);
    }
    else
    {
        temp = start;
        ptr = start->next;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = NULL;
        printf("deleted element is %d", ptr->info);
        free(ptr);
    }
}
int deletepos()
{
    struct node *temp, *ptr;
    int i, pos;
    if (start == NULL)
    {
        printf("deletion not possible");
        return 0;
    }
    if (start->next == NULL)
    {
        temp = start;
        start = NULL;
        printf("deleted element is %d", temp->info);
        free(temp);
    }
    else
    {
        temp = start;
        for (i = 1; i < pos; i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        printf("deleted element is %d", temp->info);
        free(temp);
    }
}