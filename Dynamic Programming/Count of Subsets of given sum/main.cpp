#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>dp;

int countSubset(int arr[], int sum, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<"Dispaly the Matrix :- "<<endl;
    for(int i=0; i<=n; i++)
    {
        cout<<"\t";
        for(int j=0; j<=sum; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
return dp[n][sum];
}

int main()
{
    int n,sum;
    cout<<"Enter the size of array :- ";
    cin>>n;
    cout<<"Enter sum value :- ";
    cin>>sum;

    int arr[n];
    cout<<"Enter the array elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    dp.resize(n+1, vector<int>(sum+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(i==0)   dp[i][j] = 0;
            if(j==0)   dp[i][j] = 1;
        }
    }

    int ans = countSubset(arr, sum, n);
    cout<<"\tans = "<<ans<<endl;

    return 0;
}
