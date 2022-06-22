#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter size of vector :- ";
    cin>>n;

    vector<int>vec(n,0);
    cout<<"Enter vector elements :-"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }

    vector<vector<int>>ds;
    for(int i=0; i<pow(2,n); i++)
    {
        vector<int>l;
        for(int j=0; j<n; j++)
        {
            if((i&(1<<j))!=0)
            {
                l.push_back(vec[j]);
            }
        }
        ds.push_back(l);
    }

    //display subsets
    for(auto it:ds)
    {
        for(auto jt:it)
        {
            cout<<jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}
