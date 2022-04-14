#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"enter the number of nodes and edges :";
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v;
        cout<<"enter the pair of vertices :";
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"Graph representation By Adjacency List :-"<<endl;
     for (int i = 1; i < n+1; i++) {

        cout << "Elements at index "
             << i << ": ";

        for (auto it = adj[i].begin();
             it != adj[i].end(); it++) {

            cout << *it << ' ';
        }
        cout << endl;
    }
    return 0;
}
