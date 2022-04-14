#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *temp;

void insert_beg()
{
  struct node *new_node;
  new_node = (struct node*)malloc(sizeof(struct node));
  printf("   enter the data :");
  scanf("%d",&new_node->data);
  if(start == NULL)
  {
      start = new_node;
      new_node->next = start;
  }
  else
  {
      struct node *temp=start;
      while(temp->next != start)
      {
          temp = temp->next;
      }

      new_node->next=start;
      start = new_node;
      temp->next = new_node;
  }
}

void insert_end()
{
    struct node *new_node;
    struct node *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("   Enter the data :");
    scanf("%d",&new_node->data);
   if(start == NULL)
   {
      start=new_node;
      new_node->next=start;
   }
   else
   {
       temp = start;
       while(temp->next != start)
       {
           temp = temp->next;
       }
       temp->next=new_node;
       new_node->next=start;
   }
}
void insert_after()
{
    struct node *new_node;
    struct node *temp;
    struct node *temp1;
    int n;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("   Enter the data of a node after which which you want to add new_node :");
    scanf("%d",&n);
    printf("   enter the data to be inserted in list :");
    scanf("%d",&new_node->data);
    temp = start;
    temp1 = start;

    while(temp->data != n)
    {
       temp = temp->next;
       if(temp == start)
       {
           printf("   Element is  not present\n");
           return ;
       }
    }
    if(temp->next == start)
    {
        temp->next = new_node;
        new_node->next = start;
    }
    else
    {
        temp1 = temp->next;

        temp->next=new_node;
        new_node->next = temp1;
    }

}

void update()
{
    int actual_data,updated_data;
    struct node *temp;
    printf("   Enter the actual data value:");
    scanf("%d",&actual_data);
    printf("   Enter the new data to be inserted:");
    scanf("%d",&updated_data);
    if(start==NULL)
    {
        printf("   There is no node to be updated\n");
    }
    else
    {
        int flag=0;
        temp=start;
        do
        {
            if(temp->data == actual_data)
            {
                flag=1;
                break;
            }
            temp = temp->next;
        }while(temp != start);
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
            printf("\n   The data to be updated is not available in the list\n");
        }
    }

}
void delete_from()
{

    struct node *temp,*ptemp;
    int n;
    printf("   Enter the elemenet to be deleted from list :");
    scanf("%d",&n);
    temp = start;
    if(start->data == n) //for deleting first node
    {
        if(start->next == start) //if only one node is present in list
        {
            free(start);
            start = NULL;
        }
        else //for multiple nodes
        {
            start = start->next;
            free(temp);
            temp=start;
            while(temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = start;

        }
    }
    else //for deleting other than first node
    {
        while(temp->data != n)
        {
           ptemp = temp;
           temp = temp->next;
           if(temp == NULL)
           {
               printf("   %d is not present in list\n",n);
               return;
           }
        }
        if(temp->next == start) // for deleting last node
        {
            ptemp->next = start;
            free(temp);
        }
        else
        {
            ptemp->next = temp->next;
            free(temp);
        }
    }

}
void display()
{
    struct node *temp;
    temp = start;
    if(start == NULL)
    {
        printf("   SLL is empty\n");
        return;
    }
    do
    {
        printf("   %d\t",temp->data);
        temp=temp->next;
    } while(temp != start);

}


int main()
{
    int choice;
    do
    {
        printf("\n1.insert_beg  2.insert_end  3.insert_after  4.update  5.delete_from  6.display    7.EXIT\n");
        printf("   Enter the choice :");
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
