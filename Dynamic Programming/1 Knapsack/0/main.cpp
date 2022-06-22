#include <bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int c, int n)
{
    if(n==0 || c==0)     return 0;

    if(wt[n-1]<=c)
    {
        return max(val[n-1]+knapsack(wt,val,c-wt[n-1],n-1), knapsack(wt,val,c,n-1));
    }
    return knapsack(wt,val,c,n-1);
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

    cout<<"\tEnter the weight and value in array :- "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>wt[i];
        cin>>val[i];
    }

    cout<<"\tMax Profit :- "<<knapsack(wt,val,c,n);

    return 0;
}
