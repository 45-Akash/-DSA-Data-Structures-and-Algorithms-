#include <bits/stdc++.h>

using namespace std;

vector<int>parent;


int Find(int v)
{
    if(parent[v]==-1) return v;
    return Find(parent[v]);
}

void union_fun(int from, int to)
{
    from = Find(from);
    to = Find(to);
    parent[from] = to;
}

bool isCyclic(vector<pair<int,int>>&AdjList)
{

    for(auto it : AdjList)
    {
        int from = Find(it.first);
        int to = Find(it.second);

        if(from==to)    return true;

        union_fun(from,to);
    }
    return false;
}
int main()
{
    int E,V;
    cout<<"Enter The Number of Edges :-";
    cin>>E;
    cout<<"Enter The Number of Vertices :-";
    cin>>V;

    vector<pair<int,int>>AdjList;
    parent.resize(V+1, -1);
    for(int i=0; i<E; i++)
    {
        int from,to;
        cin>>from>>to;
        AdjList.push_back({from,to});
    }

    if(isCyclic(AdjList))
    {
        cout<<"Cycle exist"<<endl;
    }
    else
    {
        cout<<"Cycle does not exist"<<endl;
    }
    return 0;
}
