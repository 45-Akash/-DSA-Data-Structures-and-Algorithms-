#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;       //enter the number of nodes and edges
    cout<<"enter the number of nodes and edges :";
    cin>>n>>m;

   vector<vector<int>> adj( n+1 , vector<int> (n+1, 0));  //create matrix
    for(int i=0; i<m; i++)
    {
        int u,v;
        cout<<"enter the pair of vertices :";
        cin>>u>>v;


         adj[u][v]=1;
         adj[v][u]=1;                    //for undirected graph
    }

    cout<<"Graph representation By Adjacency matrix :-"<<endl;
      for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
