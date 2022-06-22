#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<bool>check;

int Find(int v)
{
    if(parent[v]==-1) return v;
    return Find(parent[v]);
}


bool isCycle(int from, int to)
{
    int fromP = Find(from);
    int toP = Find(to);

    if(fromP==toP)    return true;

    parent[fromP] = toP;    //union operation
    return  false;
}

int MSTprims(vector<pair<int,int>>adjList[], int mCost, int Edge,int V)
{
    set<int>st;
    int start = 0;
    st.insert(0);

    while(st.size() != V)
    {
        if(check[start])
        {
            check[start]=0;

            vector<vector<int>>v;

            for(auto it : adjList[start])
            {
                if(check[it.first])
                {
                    vector<int>vec;
                    vec.push_back(it.second);
                    vec.push_back(it.first);

                    v.push_back(vec);
                }
            }

            sort(v.begin(), v.end());

            for(int j=0; j<v.size(); j++)
            {
                if(!isCycle(start,v[j][0]))
                {
                    mCost +=  v[j][1];
                    start = v[j][0];
                    st.insert(v[j][0]);
                    break;
                }
            }
        }

    }
return mCost;
}


int main()
{
    int E , V;
    cout<<"\tEnter the number of Edges:-";
    cin>>E;
    cout<<"\tEnter the number of vertice:-";
    cin>>V;

    parent.resize(V+1, -1);
    check.resize(V+1, true);
    vector<pair<int,int>> adjList[E+1];

    //Input Graph
    for(int i=0; i<E; i++)
    {
        int w,from,to;
        cout<<"\tEnter Weight source destination :- ";
        cin>>w>>from>>to;
        pair <int,int> p = {to,w};
        adjList[from].push_back(p);

        pair <int,int> p1 = {from,w};
        adjList[to].push_back(p1);
    }

    int mCost = MSTprims(adjList, 0, E, V);

    //Print Minimum cost
    cout<<"\t\tMST is :- "<<mCost<<endl;


    //Display Graph
    /*cout<<"Source Destination Weight :-"<<endl;
    for(int i=0; i<E; i++)
    {
        for(auto it : adjList[i])
        {
            cout<<i<<" "<<it.first<<" "<<it.second<<endl;
        }
    }*/

}


/*
Enter the number of Edges:-5
Enter the number of vertice:-4
Enter Weight source destination :- 2 1 2
Enter Weight source destination :- 3 2 3
Enter Weight source destination :- 5 3 0
Enter Weight source destination :- 1 0 1
Enter Weight source destination :- 4 0 2
MST is :- 6
Source Destination Weight :-
0 3 5
0 1 1
0 2 4
1 2 2
1 0 1
2 1 2
2 3 3
2 0 4
3 2 3
3 0 5

Process returned 0 (0x0)   execution time : 43.289 s
Press any key to continue.
*/
