#include <stdio.h>
#include <stdlib.h>
char stack[100];
int top=-1;

void push(char c)
{
    stack[++top]=c;
}
void pop()
{
    if(top==-1)
    {
       printf("No");
       exit(0);
    }
    else{
     top--;
    }
}

int main()
{
    char str[100];
    int flag=0,i=0;
    scanf("%s",str);
    while(str[i]!='\0')
    {
        if(str[i]=='A')
        {
            if(flag==0)
            {
                  push('A');
            }
            else
            {
                return printf("No");

            }
        }
        else
        {
            flag=1;
            pop();
        }
        i++;
    }
    if(top==-1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
