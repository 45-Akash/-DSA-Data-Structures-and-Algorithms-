#include <stdio.h>
#include <stdlib.h>
//Implementation of Queue
//B-63
int front=-1;
int rare=-1;
int queue[5];
void enqueue()
{
    int element;
    if(rare == 4)
        {
            printf("\nQueue is overflow\n");
            exit(0);
        }
    else if(rare==-1 && front==-1)
    {
        rare++;
        front++;
        printf("take input\n");
        scanf("%d",&element);
        queue[rare] = element;

    }
    else
    {
        rare++;
        printf("take input\n");
        scanf("%d",&element);
        queue[rare] = element;
    }

}
void dequeue()
{

   if(front == -1 )
   {
       printf("Queue is underflow\n");
       exit(0);
   }
   else if(rare == front)
   {
       printf("\n%d is deleted from queue \n",queue[front]);

       rare =-1;
       front=-1;
   }
   else
   {
       printf("\n%d is deleted from queue \n",queue[front]);
       front++;
   }
}
void display()
{
    int i;
    if(rare==-1 && front == -1)
    {
      printf("Queue is Empty\n");
      exit(0);
    }
    for(i=front; i<=rare; i++)
    {
        printf("%d\t",queue[i]);
    }

}

int main()
{
    int n;
    do{
    printf("\n 1: Enqueue \n 2: Dequeue \n 3: Display \n 4: Exit\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        printf("Exit the programe.....");
        exit(0);
    }

    }while(n!=4);


    return 0;
}
