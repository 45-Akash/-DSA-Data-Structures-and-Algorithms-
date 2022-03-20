#include <bits/stdc++.h>

using namespace std;

char st[10];
int top=-1;

void push(char ch);
void pop();

int main()
{
    string str;
    cout<<"Enter a string : ";
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(')              push('(');
        else
        {
            if(top==-1)
            {
                cout<<"string is not balanced"<<endl;                  //   )()()(
                exit(0);
            }
            pop();
        }
    }
    if(top==-1)          cout<<"string is balanced"<<endl;
    else                 cout<<"string is not balanced"<<endl;
    return 0;
}

void push(char ch)
{
    top++;
    st[top]=ch;
}
void pop()
{
    top--;
}
