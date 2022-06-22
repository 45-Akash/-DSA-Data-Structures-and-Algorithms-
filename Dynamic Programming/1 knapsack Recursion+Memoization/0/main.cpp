#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Dp;

int knapsack(int wt[], int val[], int c, int n)
{
    if(n==0 || c==0)     return 0;

    if(Dp[c][n] != -1)   return Dp[c][n];    //if the ans for the sub-problem is previsouly calculated

    if(wt[n-1]<=c)
    {
        return Dp[c][n]=max(val[n-1]+knapsack(wt,val,c-wt[n-1],n-1), knapsack(wt,val,c,n-1));
    }
    return Dp[c][n]=knapsack(wt,val,c,n-1);
}
int main()
{
    int n,c;
    cout<<"\tEnter the Size of the array :- ";
    cin>>n;
    cout<<"\tEnter the capacity of knapsack :- ";
    cin>>c;

    int wt[n];
    int val[n];

    Dp.resize(n+1,vector<int>(c+1));
    for(int i=0; i<c+1; i++)
    {
        for(int j=0; j<n+1; j++)     Dp[i][j] = -1;
    }


    cout<<"\tEnter the weight and value in array :- "<<endl<<"\t";
    for(int i=0; i<n; i++)
    {
        cin>>wt[i];
        cin>>val[i];
        cout<<"\t";
    }

    cout<<endl<<"\t\tMax Profit :- "<<knapsack(wt,val,c,n);

    return 0;
}
