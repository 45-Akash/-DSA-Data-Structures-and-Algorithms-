#include <bits/stdc++.h>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>>&mat, int n, vector<vector<int>>&visited)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && mat[x][y]==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void maze(vector<vector<int>>&mat, int n, vector<vector<int>>&visited, vector<string>&ans, string path, int x, int y)
{
    //Base Case
    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
    }

    visited[x][y]=1;

    //Rat moves Down
    if(isSafe(x+1, y, mat, n, visited))
    {
        path+='D';
        maze(mat, n, visited, ans, path, x+1, y);
        //pop for backtracking
        path.pop_back();
    }

    //Rat moves Up
    if(isSafe(x-1, y, mat, n, visited))
    {
        path+='U';
        maze(mat, n, visited, ans, path, x-1, y);
        //pop for backtracking
        path.pop_back();
    }

    //Rat moves Left
    if(isSafe(x, y-1, mat, n, visited))
    {
        path+='L';
        maze(mat, n, visited, ans, path, x, y-1);
        //pop for backtracking
        path.pop_back();
    }

    //Rat moves Right
    if(isSafe(x, y+1, mat, n, visited))
    {
        path+='R';
        maze(mat, n, visited, ans, path, x, y+1);
        //pop for backtracking
        path.pop_back();
    }



    //Mark as unvisited for backtracking
    visited[x][y]=0;
}

int main()
{
    //INPUT
    int n;
    cin>>n;

    vector<vector<int>>mat(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int val;
            cin>>val;
            mat[i].push_back(val);
        }
    }

    //PROCESS
    if(mat[0][0]==0 || mat[n-1][n-1]==0)
    {
        cout<<"Rat cannot move to final state"<<endl;
    }
    else
    {
        //Initial position of rat
        int x=0;
        int y=0;
        //make a answer vector to store all paths
        vector<string>ans;
        //take a visited mat
        vector<vector<int>>visited=mat;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)   visited[i][j]=0;
        }

        maze(mat, n, visited, ans, "", x, y);

        for(auto it:ans)
        {
            cout<<it<<" ";
        }
    }
    return 0;
}
