#include <stdio.h>
#include <stdlib.h>

//Implementation of priority queue
struct node
{
    int priority;
    struct node *next;
    int data;
};


struct node *front = NULL;

void Enqueue()
{
   struct node *new_node;
   new_node = (struct node*)malloc(sizeof(struct node));
   printf("   Enter the element you want to insert in Queue and priority of the node: ");
   scanf("%d%d",&new_node->data,&new_node->priority);

   if(front == NULL)
   {
       front = new_node;
       new_node->next = NULL;
   }
   else
   {
       if(new_node->priority < front->priority)
       {
           new_node->next = front;
           front = new_node;
       }
       else
       {
           struct node *temp = front;
           while((temp->next != NULL) && (temp->next->priority < new_node->priority))
           {
               temp = temp->next;
           }
           new_node->next = temp->next;
           temp->next = new_node;
       }
   }
}
void Dequeue()
{
    if(front == NULL)
    {
        printf("   Queue is empty\n");
        return;
    }
    else
    {

            struct node *temp;
            temp = front;
            printf("   %d is deleted from Queue\n",front->data);
            front = temp->next;
            free(temp);


    }

}
void display()
{
    struct node *temp;
    temp = front;
    if(front == NULL)
    {
         printf("   Queue is empty\n");
         return;
    }
    else
    {
        while(temp != NULL)
        {
            printf("   %d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

}
int main()
{
    int choice;
    do
    {
        printf("\n 1:Enqueue  2:Dequeue  3:Dispaly  4:Exit\n");
        printf("   Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nEnd of program...... :-)\n");
                break;
        }
    }while(choice != 4);
    return 0;
}
