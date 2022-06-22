#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>dp;

int knapsack(int wt[], int val[], int c, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
return dp[n][c];
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
    dp.resize(c,vector<int>(n));

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=c; j++)
        {
            if(i==0 || j==0)     dp[i][j]=0;
        }
    }

    cout<<"\tEnter the weight and value in array :- "<<endl<<"\t";
    for(int i=0; i<n; i++)
    {
        cin>>wt[i];
        cin>>val[i];
        cout<<"\t";
    }

    cout<<endl<<"\t\tMax Profit :- "<<knapsack(wt,val,c,n);
    cout<<endl;

    return 0;
}
