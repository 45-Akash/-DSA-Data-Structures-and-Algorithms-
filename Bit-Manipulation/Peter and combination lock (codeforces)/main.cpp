#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n,0);

    for(int i=0; i<n; i++)     cin>>vec[i];

    int flag=0;
    for(int i=0; i<pow(2,n); i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            if(i&(1<<j))   sum+=vec[j];
            else           sum-=vec[j];
        }
        if(sum%360==0)
        {
            flag=1;
            break;
        }
    }

    if(flag)    cout<<"YES"<<endl;
    else        cout<<"NO"<<endl;
    return 0;
}
