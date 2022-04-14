#include <stdio.h>
#include <stdlib.h>
#define size 5
/*ROLL NO B-63
  WRITE MENU DRIVEN PROGRAM TO IMPLEMENT STACK USING ARRAY OF SIZE 5
*/
int top=-1;
int a[size];

void push()
{
    int element;
    if(top==size-1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    else
    {
        printf("Enter the element to be inserted into stack  ");
        scanf("%d",&element);
        top=top+1;
        a[top]=element;

    }


}
void pop()
{
    if(top==-1)
    {
        printf("STACK IS UNDERFLOW\n");
        return;
    }
    else
    {
        printf("The number %d is deleted from stack  \n",a[top]);
        top=top-1;
    }


}
void display()
{
    int i;
    printf("Display The stack\n");
    for(i=0;i<=top;i++)
    {
        printf("%d\n",a[i]);
    }

}

int main()
{
    int choice;
    do
    {
        printf("\n1:push 2:pop 3:display 4:exit\n");
        scanf("%d",&choice);


    switch(choice)
      {
        case 1:
            {
                push();
                break;
            }
        case 2:
            {
                pop();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                printf("End of program....\n");
                break;
            }
       }

    }while(choice!=4);

    return 0;
}

/*
1:push 2:pop 3:display 4:exit
1
Enter the element to be inserted into stack  45

1:push 2:pop 3:display 4:exit
1
Enter the element to be inserted into stack  27

1:push 2:pop 3:display 4:exit
1
Enter the element to be inserted into stack  10

1:push 2:pop 3:display 4:exit
2
The number 10 is deleted from stack

1:push 2:pop 3:display 4:exit
1
Enter the element to be inserted into stack  264

1:push 2:pop 3:display 4:exit
1
Enter the element to be inserted into stack  100

1:push 2:pop 3:display 4:exit
3
Display The stack
45
27
264
100

1:push 2:pop 3:display 4:exit
1
Enter the element to be inserted into stack  90

1:push 2:pop 3:display 4:exit
1
STACK OVERFLOW

1:push 2:pop 3:display 4:exit
3
Display The stack
45
27
264
100
90

1:push 2:pop 3:display 4:exit
2
The number 90 is deleted from stack

1:push 2:pop 3:display 4:exit
2
The number 100 is deleted from stack

1:push 2:pop 3:display 4:exit
2
The number 264 is deleted from stack

1:push 2:pop 3:display 4:exit
2
The number 27 is deleted from stack

1:push 2:pop 3:display 4:exit
2
The number 45 is deleted from stack

1:push 2:pop 3:display 4:exit
2
STACK IS UNDERFLOW

1:push 2:pop 3:display 4:exit
4
End of program....

Process returned 0 (0x0)   execution time : 118.205 s
Press any key to continue.
*/
