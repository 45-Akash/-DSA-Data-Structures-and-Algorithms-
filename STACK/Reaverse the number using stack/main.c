#include <stdio.h>
#include <stdlib.h>
#define size 5
//ROLL NO : B-63
int top=-1;
int stack[size];

void push()
{
    if(top==size-1)
    {
        printf("Stack Overflow\n");
        return ;
    }
    else
    {
        printf("take inputs \n");
            for(int i=0;i<size;i++)
            {
                top++;
                scanf("%d",&stack[i]);

            }
    }
}

void display()
{
   int y;
    if(top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    else
    {
      printf("The reverse of given series of degits is\n");
        for(int i=0;i<size;i++)
       {
           y=stack[top];
           printf("%d ",y);
           top--;
       }
    }

}

int main()
{
    int choice;
     do
    {
    printf("\n 1: Enter the digits of number which has to reverse \n 2: Display the reversed number\n 3: End of programe\n");
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
            display();
            break ;
        }
    case 3:
        {
            printf("End programe......\n");
            break;
        }

    }
    }while(choice!=3);



    return 0;
}
/*
 1: Enter the digits of number which has to reverse
 2: Display the reversed number
 3: End of programe
1
take inputs
2 17 97 50 34

 1: Enter the digits of number which has to reverse
 2: Display the reversed number
 3: End of programe
2
The reverse of given series of degits is
34 50 97 17 2
 1: Enter the digits of number which has to reverse
 2: Display the reversed number
 3: End of programe
3
End programe......

Process returned 0 (0x0)   execution time : 96.648 s
Press any key to continue.
*/
