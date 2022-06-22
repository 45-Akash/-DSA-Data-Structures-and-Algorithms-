#include <iostream>

using namespace std;

int power(int base, int p)
{
    if(p==0)    return 1;
    if(p==1)    return base;

    int ans = power(base,p/2);

    if(p%2==0)
    {
        return ans*ans;
    }
    return base*ans*ans;
}
int main()
{
    int base,p;
    cin>>base>>p;

    cout<<power(base,p)<<endl;
    return 0;
}
