#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe;
    int exp;
    struct node *next;
};

struct node *poly1=NULL;
struct node *poly2=NULL;
struct node *result=NULL;

void insert_poly1()
{
    struct node *new_node;
    //struct node *temp = poly1;
    int n;
    printf("  Enter the number of terms of first polynomial :");
    scanf("%d",&n);
    while(n--)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("   ENter the coeficient and exponent :");
        scanf("%d%d",&new_node->coe,&new_node->exp);
         struct node *temp = poly1;
        if(poly1==NULL)
        {
            poly1 = new_node;
            new_node->next = NULL;
        }
        else
        {
            while(temp->next != NULL)
            {
               temp = temp->next;
            }

            temp->next = new_node;
            new_node->next = NULL;
        }
    }
}

void insert_poly2()
{
    struct node *new_node;
    //struct node *temp = poly2;
    int n;
    printf("  Enter the number of terms of second polynomial :");
    scanf("%d",&n);
    while(n--)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("   ENter the coeficient and exponent :");
        scanf("%d%d",&new_node->coe,&new_node->exp);
        struct node *temp = poly2;
        if(poly2==NULL)
        {
            poly2 = new_node;
            new_node->next = NULL;
        }
        else
        {
            while(temp->next != NULL)
            {
               temp = temp->next;
            }

            temp->next = new_node;
            new_node->next = NULL;
        }
    }
}

void insert_3(int x, int y)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->coe = x;
    new_node->exp = y;
    struct node *temp=result;
    if(result == NULL)
    {
        result = new_node;
        new_node->next = NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
}

void Addition()
{
    struct node *p,*q;
    p = poly1;
    q = poly2;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp == q->exp)
        {
            insert_3(p->coe + q->coe, p->exp);
            p = p->next;
            q = q->next;
        }
        else if(p->exp < q->exp)
        {
            insert_3( q->coe, q->exp);
            q = q->next;
        }
        else if(p->exp > q->exp)
        {
            insert_3( p->coe, p->exp);
            p = p->next;
        }
    }

    while(p!=NULL)
    {
        insert_3( p->coe, p->exp);
        p = p->next;
    }
    while(q!=NULL)
    {
        insert_3( q->coe, q->exp);
        q = q->next;
    }
}

void display()
{
    struct node *temp = result;
    printf("  Coeficient and exponents of result\n");
    while(temp!=NULL)
    {
        printf("  %dX^%d ||",temp->coe,temp->exp);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    /*int choice;
    do
    {
        printf("\n1:insert_poly1  2:insert_poly2  3:Addition  4:display  5: exit\n");
        printf("  Enter the choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_poly1();
            break;
        case 2:
            insert_poly2();
            break;
        case 3:
            Addition();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exit.....!\n");
            break;

        }
    }while(choice!=5);*/

     insert_poly1();
     printf("\n");

     insert_poly2();
     printf("\n");

     Addition();
     printf("\n");

     display();
    return 0;
}
/*
  Enter the number of terms of first polynomial :3
   ENter the coeficient and exponent :5 2
   ENter the coeficient and exponent :7 1
   ENter the coeficient and exponent :8 0

  Enter the number of terms of second polynomial :4
   ENter the coeficient and exponent :6 3
   ENter the coeficient and exponent :5 2
   ENter the coeficient and exponent :9 1
   ENter the coeficient and exponent :3 0


  Coeficient and exponents of result
  6X^3 ||  10X^2 ||  16X^1 ||  11X^0 ||

Process returned 0 (0x0)   execution time : 28.748 s
Press any key to continue.
*/
