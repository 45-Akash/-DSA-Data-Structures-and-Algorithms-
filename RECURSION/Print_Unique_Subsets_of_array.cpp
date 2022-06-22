#include <bits/stdc++.h>

using namespace std;


void uniqueSubsets(int size, int ind, vector<int>&vec, vector<int>&ds, set<vector<int>>&st)
{
    if(ind == size)
    {
       st.insert(ds);
       return;
    }
    
    ds.push_back(vec[ind]);
    uniqueSubsets(size, ind+1, vec, ds, st);
    
    ds.pop_back();
    uniqueSubsets(size, ind+1, vec, ds, st);
    
    return;
}

int main()
{
    vector<int>vec;
    for(int i=0; i<5; i++)
    {
        int in;
        cin>>in;
        vec.push_back(in);
    }
    
    vector<int>ds;
    set<vector<int>>st;
    uniqueSubsets(5, 0, vec, ds, st);
    
    for(auto it : st)
    {
        for(auto iter : it)
        {
            cout<<iter<<" ";
        }
        cout<<endl;
    }

    return 0;
}