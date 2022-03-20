#include <bits/stdc++.h>

using namespace std;

char st[10];
int top=-1;

void push(char ch);
void pop();

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        push(str[i]);
    }
    cout<<"Before reverse : "<<str<<endl;
    cout<<"After reverse : ";
    while(top!=-1)      pop();
    return 0;
}

void push(char ch)
{
    top++;
    st[top]=ch;
}

void pop()
{
    cout<<st[top];
    top--;
}
