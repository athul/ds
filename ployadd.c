#include<stdio.h>
#include<stdlib.h>
struct node
{
 int coeff;
 int pow;
 struct node *next;
};
void create_node(int x,int y,struct node **temp)
{
 struct node *r,*z;
 z=*temp;
 if(z==NULL)
 {
  r=(struct node *)malloc(sizeof(struct node));
  r->coeff=x;
  r->pow=y;
  *temp=r;
  r->next=(struct node *)malloc(sizeof(struct node));
  r=r->next;
  r->next=NULL;
 }
 else
 {
  r->coeff=x;
  r->pow=y;
  r->next=(struct node *)malloc(sizeof(struct node));
  r=r->next;
  r->next=NULL;
 }
}
void polyadd(struct node *poly1,struct node *poly2,struct node *poly)
{
 while(poly1->next && poly2->next)
 {
  if(poly1->pow>poly2->pow)
  {
   poly->pow=poly1->pow;
   poly->coeff=poly1->coeff;
   poly1=poly1->next;
  }
  if(poly1->pow<poly2->pow)
  {
   poly->pow=poly2->pow;
   poly->coeff=poly2->coeff;
   poly2=poly2->next;
  }
  else 
  {
   poly->pow=poly1->pow;
   poly->coeff=poly->coeff + poly2->coeff;
   poly1=poly1->next;
   poly2=poly2->next;
   poly->next=(struct node *)malloc(sizeof(struct node));
   poly=poly->next;
   poly->next=NULL;
  }
 } 
 while(poly1->next || poly2->next)
 {
  if(poly1->next)
  {
   poly->pow=poly1->pow;
   poly->coeff=poly1->coeff;
   poly1=poly1->next;
  }
  if(poly2->next)
  {
   poly->pow=poly2->pow;
   poly->coeff=poly2->coeff;
   poly2=poly2->next;
  }
  poly->next=(struct node *)malloc(sizeof(struct node));
  poly=poly->next;
  poly->next=NULL;
 }
}
void show(struct node *node)
{
 while(node->next!=NULL)
 {
  printf("%dx^%d",node->coeff,node->pow);
  node=node->next;
  if(node->next!=NULL)
  {
   printf("+");
  }
 }
}
void main()
{
 struct node *poly1=NULL,*poly2=NULL,*poly=NULL;
 int a,b,c,l,m,n,pa,pl,pb,pm;
 printf("enter power and coeff of first poly:");
 scanf("%d %d",&a,&pa);
 printf("enter power and coeff of first poly:");
 scanf("%d %d",&b,&pb);
 printf("enter the constant term:");
 scanf("%d",&c);
 printf("enter power and coeff of second poly:");
 scanf("%d %d",&l,&pl);
 printf("enter power and coeff of second poly:");
 scanf("%d %d",&m,&pm);
 printf("enter constant :");
 scanf("%d",&n);
 create_node(a,pa,&poly1);
 create_node(b,pb,&poly1);
 create_node(c,0,&poly1);
 create_node(l,pl,&poly2);
 create_node(m,pm,&poly2);
 create_node(n,0,&poly2);
 printf("first number is:");
 show(poly1);
 printf("\nsecond number is:");
 show(poly2);
 poly=(struct node *)malloc(sizeof(struct node));
 polyadd(poly1,poly2,poly);
 printf("\nadded polynomial is:");
 show(poly);
}
   
