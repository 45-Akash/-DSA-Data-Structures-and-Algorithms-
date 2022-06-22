#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int x;
    cout<<"Enter the number x :- "<<endl;
    cin>>x;

    cout<<endl<<"XOR"<<endl;
    cout<<"\tX^0s=X\t"<<(x^0)<<endl;
    cout<<"\tX^1s=~X\t"<<(x^1)<<endl;
    cout<<"\tX^X=0\t"<<(x^x)<<endl;

    cout<<endl<<"AND"<<endl;
    cout<<"\tX&0s=0\t"<<(x&0)<<endl;
    cout<<"\tX&1s=X\t"<<(x&1)<<endl;
    cout<<"\tX&X=X\t"<<(x&x)<<endl;

    cout<<endl<<"OR"<<endl;
    cout<<"\tX|0s=X\t"<<(x|0)<<endl;
    cout<<"\tX|1s=1\t"<<(x|1)<<endl;
    cout<<"\tX|X=X\t"<<(x|x)<<endl;

    return 0;
}
