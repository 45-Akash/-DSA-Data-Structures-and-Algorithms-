#include <stdio.h>
#include <stdlib.h>
//IMPLEMENTATION OF CIRCULAR QUEUE
//B-63
#define size 5
int rear=-1,front=-1;
int queue[size];
void EQ()
{
    int element;
    if(rear==-1 && front==-1)
    {
        front=0;
        rear=0;
        printf("\nenter the element\n");
        scanf("%d",&element);
        queue[rear]=element;
    }
    else if((rear+1)%size == front)
    {
       printf("\n Queue overflow\n");
       exit(0);
    }
    else /*if((rear+1)%size != front)*/
    {
        rear=(rear+1)%size;
        printf("\nenter the element\n");
        scanf("%d",&element);
        queue[rear]=element;
    }


}
void DQ()
{
   if(rear==-1 && front==-1)
   {
       printf("\n Queue Underflow\n");
       exit(0);
   }
   else if(rear == front)
   {
       printf("\n%d is deleted from Queue ",queue[front]);
       front=-1;
       rear=-1;
   }
   else /*if((front+1)%size != rear)*/
   {
       printf("\n%d is deleted from Queue ",queue[front]);
       front=(front+1)%size;
   }

}
void display()
{
    int i=front;
    if(rear==-1 && front==-1)
    {
        printf("\n Queue is Empty\n");
        exit(0);
    }

    do//while(i != (rear+1)%size )
    {

        printf("%d ",queue[i]);
        i=(i+1)%size;

    } while(i != (rear+1)%size );

    return;
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
        EQ();
        break;
    case 2:
        DQ();
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
