#include <bits/stdc++.h>

using namespace std;

vector<int>parent;
vector<vector<int>>mst;


void printMST()
{
    cout<<"--------------------MST Representation---------------------------"<<endl;
    cout<<"\tWeight Source Destination :-"<<endl;
    for(auto &it : mst)
    {
        cout<<"\t";
        for(auto &jt : it)
        {
            cout<<jt<<"      ";
        }
        cout<<endl;
    }
}
int Find(int v)
{
	if(parent[v]==-1)
		return v;
	return Find(parent[v]);	//Path Compression
}

void union_fun(int fromP,int toP)
{
	parent[fromP] = toP;
}

bool isCycle(int from, int to)
{
    int fromP = Find(from);
    int toP = Find(to);

    if(fromP==toP)    return true;

    parent[fromP] = toP;    //union operation
    return  false;
}

int kruskals(vector<vector<int>> &Graph, int V, int E, int cost)
{
    sort(Graph.begin(), Graph.end());
    cout<<endl<<"\tsorted by weight "<<endl;

    for(auto &it : Graph)
    {
        for(auto &jt : it)
        {
            cout<<jt<<" ";
        }
        cout<<endl;
    }

    int i=0, j=0;
    while(i < V-1 && j < E)
    {

        if(isCycle(Graph[j][1],Graph[j][2]))
        {
            j++;
            continue;
        }
        cost += Graph[j][0];
        mst.push_back(Graph[j]);
        j++;
        i++;
    }
return cost;
}
int main()
{
    int E,V;
    cout<<"\tEnter the number of Edges :- ";
    cin>>E;
    cout<<"\tEnter the number of Vertices :- ";
    cin>>V;

    parent.resize(V, -1);


    vector<vector<int>> Graph;
    //Input the Graph
    cout<<"\tWeight Source Destination :-"<<endl;
    for(int i=0; i<E; i++)
    {
        vector<int>v;
        int w,s,d;
        cin>>w>>s>>d;
        v.push_back(w);
        v.push_back(s);
        v.push_back(d);
        Graph.push_back(v);
    }

    int mCost = kruskals(Graph, V, E, 0);
    cout<<endl<<"\tMinimum cost is :- "<<mCost<<endl;

    //Print MST
    printMST();

    return 0;
}
