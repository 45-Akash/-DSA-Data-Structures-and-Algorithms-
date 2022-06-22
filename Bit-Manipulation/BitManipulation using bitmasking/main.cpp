#include <bits/stdc++.h>

using namespace std;

bool checkBit(int x, int pos)
{
    if(x&(1<<pos))  return true;
    return false;
}

int setBit(int x, int pos)
{
    return (x|(1<<pos));
}

int clearBit(int x, int pos)
{
    return (x & ~(1<<pos));
}

int main()
{
    int choice;
    cout<<endl;
    int x;
    cout<<"Enter the element x :- ";
    cin>>x;


    do
    {
        cout<<endl<<"1.check-bit\t2.get-bit\t3.set-bit\t4.clear-bit\t5.EXIT"<<endl;
        cout<<"Enter choice :- ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    int bitpos;
                    cout<<"Enter bit position :- ";
                    cin>>bitpos;
                    if(checkBit(x,bitpos))
                        cout<<"bit is set"<<endl;
                    else
                        cout<<"bit is not set"<<endl;

                    break;
                }

            case 2:
                {
                    int bitpos;
                    cout<<"Enter bit position :- ";
                    cin>>bitpos;
                    if(checkBit(x,bitpos))
                        cout<<"pos th bit is 1"<<endl;
                    else
                        cout<<"pos th bit is 0"<<endl;
                    break;
                }
            case 3:
                {
                    int bitpos;
                    cout<<"Enter bit position :- ";
                    cin>>bitpos;

                    cout<<"x before setting pos th bit="<<x<<endl;
                    x = setBit(x,bitpos);
                    cout<<"x after setting pos th bit="<<x<<endl;

                    break;
                }
            case 4:
                {
                    int bitpos;
                    cout<<"Enter bit position :- ";
                    cin>>bitpos;
                    cout<<"x before clearing pos th bit="<<x<<endl;
                    x = clearBit(x,bitpos);
                    cout<<"x before clearing pos th bit="<<x<<endl;
                    break;
                }
            case 5:
                {
                    cout<<"Happy coading :-) "<<endl;
                }
            default:
                {
                    exit(0);
                }
        }
    }while(choice!=5);
    return 0;
}
