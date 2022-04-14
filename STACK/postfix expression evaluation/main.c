#include <stdio.h>
#include <stdlib.h>
// #include<ctype.h>
int top = -1;
int stack[100];

void push(int num)
{
    stack[++top]=num;
}
int pop()
{

    return stack[top--];
}

int main()
{
    int num1,num2,result,i=0;
    char str[100];
    printf("Enter the input expression\n");
    scanf("%s",str);
    while(str[i]!='\0')
    {
      if(isdigit(str[i])){
        push(str[i]-48);
      }
      else{
            num1=pop();
            num2=pop();
        if(str[i]=='+'){
            result=num2+num1;
        }
        if(str[i]=='-'){
            result=num2-num1;
        }
        if(str[i]=='*'){
            result=num2*num1;
        }
        if(str[i]=='/'){
            result=num2/num1;
        }
        push(result);
      }

      i++;
    }

    printf("Final result is = %d",pop());

    return 0;
}
