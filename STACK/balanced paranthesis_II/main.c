#include<stdio.h>
#include<stdlib.h>
char exp1[100],stack[100];
int top=-1;
char c;
void push(char c)
{
    //write your code here

        stack[++top]= c;

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
    //write your code here
    int i=0,j=0;
    //char c;
    char arr[50];
    scanf("%s",exp1);


    while(exp1[i]!='\0')
    {
        if(exp1[i]=='(' || exp1[i]=='{' || exp1[i]=='['){
            c = exp1[i];
            arr[j]=exp1[i];
            j++;
        }
        if(exp1[i]==')' || exp1[i]=='}' || exp1[i]==']'){
            //arr[j]=exp1[i];
            if( arr[j-1] == '(' && exp1[i] == ')' )
            {
                j--;
                pop();

            }
            else if( arr[j-1] == '[' && exp1[i] == ']' )
            {
                j--;
                pop();

            }
            else if( arr[j-1] == '{' && exp1[i] == '}' )
            {
                j--;
                pop();

            }
            else{
            printf("NOT BALANCED");
                exit(1);
            }
        }
        i++;

    }

    if(top == -1){
        printf("BALANCED");
    }
    else{
        printf("NOT BALANCED");
    }
return 0;

}
/*
#include<stdio.h>
#include<stdlib.h>
char exp1[100],stack[100];
int top=-1;
char c;
void push(char c)
{
    //write your code here

        stack[++top]= c;

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
    //write your code here
    int i=0,j=0;
    //char c;
    char arr[50];
    scanf("%s",exp1);


    while(exp1[i]!='\0')
    {
         if((exp1[i]>=97 && exp1[i]<=122) || exp1[i]==42 || exp1[i]==43 || exp1[i]==45 || exp1[i]==47 ||(exp1[i]>=48 && exp1[i]<=57) )
            {
                i++;
                continue;
            }
        
        else if(exp1[i]=='(' || exp1[i]=='{' || exp1[i]=='['){
            c = exp1[i];
            arr[j]=exp1[i];
            j++;
        }
          
        else if(exp1[i]==')' || exp1[i]=='}' || exp1[i]==']')
        {
            //arr[j]=exp1[i];
              
            if( arr[j-1] == '(' && exp1[i] == ')' )
            {
                j--;
                pop();

            }
            else if( arr[j-1] == '[' && exp1[i] == ']' )
            {
                j--;
                pop();

            }
            else if( arr[j-1] == '{' && exp1[i] == '}' )
            {
                j--;
                pop();

            }
            else{
            printf("NOT BALANCED");
                exit(1);
            }
        }
        i++;

    }

    if(top == -1){
        printf("BALANCED");
    }
    else{
        printf("NOT BALANCED");
    }
return 0;

}*/
