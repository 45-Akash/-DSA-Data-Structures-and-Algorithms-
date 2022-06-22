#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> dp;

int subsetSum(int arr[], int sum, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if(dp[n][sum])    return 1;
    return 0;
}

int main()
{
    int n,sum;
    cout<<"Enter the size of Array :- ";
    cin>>n;
    cout<<"Enter the value of sum :- ";
    cin>>sum;

    int arr[n];
    cout<<"Enter the Array Elements :- "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    dp.resize(n+1, vector<bool>(sum+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(i==0)    dp[i][j] = false;
            if(j==0)    dp[i][j] = true;
        }
    }

    if(subsetSum(arr, sum, n))            cout<<"YES"<<endl;
    else                                  cout<<"False"<<endl;

    return 0;
}
