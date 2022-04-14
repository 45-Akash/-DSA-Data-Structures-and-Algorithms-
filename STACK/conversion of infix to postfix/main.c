#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;

void push(char c)
{
    stack[++top]=c;
}

char pop()
{
    return stack[top--];

}

int precedence(char c)
{
    if(c=='*' || c=='/')
        return 3;
    else if(c=='+' || c=='-')
        return 2;
    else if( c==')')
        return 1;

}

int main()
{
    char str[100];
    scanf("%s",str);
    char x;
    int i=0;
    while(str[i]!='\0')
    {
       if(isalnum(str[i]))
        printf("%c",str[i]);
       else if(str[i]=='(')
        push('(');
       else if(str[i]==')')
        while((x=pop()) != '(')
            printf("%c",x);
       else{
        while(precedence(stack[top]) >= precedence(str[i]))
            printf("%c",pop());
        push(str[i]);
       }
       i++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }

    return 0;
}
