#include<stdio.h>
#include<stdlib.h>
char exp1[100],stack[100];
int top=-1;
void push(char c)
{
    //write your code here
    stack[++top]=c;
}
void pop()
{
    //write your code here
    if(top == -1){
        printf("NOT BALANCED");
        exit(1);
    }
    top--;

}
int main()
{
    char c;
    int i=0;
    scanf("%s",exp1);
    //write your code here
    while(exp1[i]!='\0'){
        if(exp1[i]=='('){
            c = '(';
            push( c);
        }
        if(exp1[i]==')'){
            pop();
        }
        i++;
    }
    if(top == -1)
    {
        printf("BALANCED");
    }
    else{
        printf("NOT BALANCED");
    }
    return 0;
}
