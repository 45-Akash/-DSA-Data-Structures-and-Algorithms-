#include <iostream>

using namespace std;

int s=5;
int arr[5];
int top=-1;

void push();
void pop();
void display();


int main()
{
    int choice;
    do
    {
        cout<<"1.push 2.pop 3.display 4.exit"<<endl;
        cin>>choice;

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
            case 4: cout<<"Exit :)"<<endl;
        }

    }while(choice != 4);

    return 0;
}

void push()
{
    if(top==s-1)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    top++;
    int ele;
    cout<<"Enter the element to be pushed onto the stack : "<<endl;
    cin>>ele;

    arr[top]=ele;
}

void pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    cout<<"Element removed from stack is = "<<arr[top]<<endl;
    top--;

}

void display()
{
    if(top==-1)
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    cout<<"stack content : ";
    for(int i=0; i<=top; i++)       cout<<arr[i]<<" ";
}
