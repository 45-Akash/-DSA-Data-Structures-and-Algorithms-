#include <stdio.h>
#include <stdlib.h>

//Implementation of queue using SLL
struct node
{
    struct node *next;
    int data;
};

struct node *rear = NULL;
struct node *front = NULL;

void Enqueue()
{
   struct node *new_node;
   new_node = (struct node*)malloc(sizeof(struct node));
   printf("   Enter the element you want to insert in Queue : ");
   scanf("%d",&new_node->data);

   if(rear == NULL)
   {
       front = rear = new_node;
       new_node->next = NULL;
   }
   else
   {
       rear->next = new_node;
       new_node->next = NULL;
       rear = new_node;
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
        if(front == rear)
        {
            printf("   %d is deleted from Queue\n",front->data);
            rear = front = NULL;

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
