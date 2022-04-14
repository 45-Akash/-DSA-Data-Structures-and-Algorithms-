#include <stdio.h>
#include <stdlib.h>
//SLL 3.1

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;


void insert_beg()
{
  struct node *new_node;
  new_node = (struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&new_node->data);
  if(start == NULL)
  {
      start = new_node;
      new_node->next = NULL;
  }
  else
  {
      new_node->next=start;
      start = new_node;
  }
}

void insert_end()
{
    struct node *new_node;
    struct node *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&new_node->data);
   if(start == NULL)
   {
      start=new_node;
      new_node->next=NULL;
   }
   else
   {
       temp = start;
       while(temp->next != NULL)
       {
           temp = temp->next;
       }
       temp->next=new_node;
       new_node->next=NULL;
   }
}
void insert_after()
{
    struct node *new_node;
    struct node *temp;
    struct node *temp1;
    int n;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of a node after which which you want to add new_node\n");
    scanf("%d",&n);
    printf("enter the data to be inserted in list\n");
    scanf("%d",&new_node->data);
    temp = start;
    temp1 = start;
    while(temp->data != n)
    {
      temp = temp->next;
    }

    temp1 = temp->next;

    temp->next=new_node;
    new_node->next = temp1;

}

void update()
{
    int actual_data,updated_data;
    struct node *temp;
    printf("Enter the actual data value:");
    scanf("%d",&actual_data);
    printf("Enter the new data to be inserted:");
    scanf("%d",&updated_data);
    if(start==NULL)
    {
        printf("There is no list to be updated");
    }
    else
    {
        int flag=0;
        temp=start;
        while(temp != NULL)
        {
            if(temp->data == actual_data)
            {
                flag=1;
                break;
            }
            temp = temp->next;
        }
        if(flag == 1)
        {
             while(temp->data!=actual_data)
            {
               temp=temp->next;
            }
            temp->data=updated_data;
        }
        else
        {
            printf("\nThe data to be updated is not available in the list\n");
        }
    }

}
void delete_from()
{
    struct node *temp,*ptemp;
    int n;
    printf("Enter the elemenet to be deleted from list\n");
    scanf("%d",&n);
    temp = start;
    if(start->data == n)
    {
        start = start->next;
        free(temp);
    }
    else
    {
        while(temp->data != n)
        {
           ptemp = temp;
           temp = temp->next;
           if(temp == NULL)
           {
               printf("%d is not present in list\n",n);
               return;
           }
        }

        ptemp->next = temp->next;
        free(temp);
    }

}
void display()
{
    struct node *temp;
    temp = start;
    if(start == NULL)
    {
        printf("SLL is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}


int main()
{
    int choice;
    do
    {
        printf("\n1.insert_beg  2.insert_end  3.insert_after  4.update  5.delete_from  6.display  7.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_after();
            break;
        case 4:
            update();
            break;
        case 5:
            delete_from();
            break;
        case 6:
            display();
            break;

        case 7:
            printf("\nEnd of programe.....!\n");
        }
    }while(choice!=7);

    return 0;
}
