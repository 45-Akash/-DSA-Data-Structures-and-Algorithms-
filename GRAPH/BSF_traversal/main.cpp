#include <bits/stdc++.h>

using namespace std;

void bfsOfGraph(int v, vector<int> adj[],vector<int>&bfs,int n)
{


    vector<int>vis(n+1,0);

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            queue<int>q;
            q.push(i);
            vis[i]=1;


            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it : adj[node])
                {

                    if(!vis[it])
                    {

                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }


}

int main()
{

    int n,v;
    cout<<"Enter the number of nodes :-";
    cin>>n;
    cout<<"Enter the number of edges :-";
    cin>>v;

    vector<int>adj[n+1];
    vector<int>bfs;

    for(int i=1; i<=v; i++)
    {
        int u,v;
        cout<<"Enter the edges values :- ";
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);


    }

    cout<<"----------------Adjacency List------------------"<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<"Elments of "<<i<<" :-";

        for(auto it : adj[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    bfsOfGraph(v,adj,bfs,n);



    cout<<"-----------------------BFS----------------------"<<endl;
    for(auto it= bfs.begin(); it!=bfs.end(); it++)
    {
        cout<<*it<<" ";
    }




    return 0;
}
