#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    cout<<"Fibonacci series of length "<<n<<" :-"<<endl;
    cout<<"0 1 ";

    int first=0;
    int second=1;

    for(int i=0; i<n-2; i++)
    {
        cout<<first+second<<" ";
        int temp = first;
        first=second;
        second=temp+second;
    }
    return 0;
}
