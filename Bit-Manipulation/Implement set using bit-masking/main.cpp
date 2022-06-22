#include <iostream>

using namespace std;

long long int add(long long int x)
{
    int val;
    cout<<"Enter the value to be added :- ";
    cin>>val;

    return (x | (1<<val));
}

long long int Remove(long long int x)
{
    int val;
    cout<<"Enter the value to be removed :- ";
    cin>>val;

    return (x & ~(1<<val));
}

void Print(long long int x)
{
    cout<<"The Elements of set are "<<x<<":- "<<endl;
    for(long long int i=0; i<=60; i++)
    {
        long long int mask = 1<<i;
        if((x&mask)!=0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    long long int x=0;
    int choice;

    do
    {
        cout<<endl<<"1.add\t 2.remove\t 3.print\t 4.Exit"<<endl;
        cout<<"enter the choice :- ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    x=add(x);
                    break;
                }
            case 2:
                {
                    x=Remove(x);
                    break;
                }
            case 3:
                {
                    Print(x);
                    break;
                }
            case 4:
                {
                    cout<<"Happy coading :-)"<<endl;
                    break;
                }
            default:
            {
                return 0;
            }
        }
    }while(choice != 4);
    return 0;
}
