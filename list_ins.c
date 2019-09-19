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
              printf("\n1.create 2.display 3.insert at begin 4.insert at end 5.insert at position\n");
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
              default:
                     printf("invalid option");
                     break;
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
                     printf("%d", ptr->info);
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
