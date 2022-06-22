#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>>Dp;

void subsetSum(int arr[], int sum, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(arr[i-1] <= j)
            {
                Dp[i][j] = Dp[i-1][j-arr[i-1]] || Dp[i-1][j];
            }
            else
            {
                Dp[i][j] = Dp[i-1][j];
            }
        }
    }
}

int main()
{
    int n,sum;
    cout<<"Enter size of array :-";
    cin>>n;

    int arr[n];
    cout<<"Enter Array elements:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sum = accumulate(arr,arr+n,0);
    Dp.resize(n+1,vector<bool>(sum+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(i==0)    Dp[i][j] = false;
            if(j==0)    Dp[i][j] = true;
        }
    }

    subsetSum(arr, sum, n);

    int i=n;
    int Min = INT_MAX;
    for(int j=0; j<sum/2; j++)
    {
        if(Dp[i][j])
        {
            Min = min(Min,sum-(2*j));
        }
    }

    cout<<endl<<"MIN Difference :- "<<Min<<endl;
    return 0;
}
