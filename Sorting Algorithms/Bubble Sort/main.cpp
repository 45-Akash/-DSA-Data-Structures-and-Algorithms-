#include <bits/stdc++.h>

using namespace std;

void BubbleSort(vector<int>&vec, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int f=0;
        for(int j=0; j<n-1-i; j++)
        {
            if(vec[j]>vec[j+1])
            {
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
                f=1;
            }
        }
        if(f==0)   break;
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter the size of Array :- ";
    cin>>n;
    vector<int>arr(n,0);

    for(int i=0; i<n; i++)     cin>>arr[i];

    BubbleSort(arr,n);

    for(auto it:arr)           cout<<it<<" ";
    return 0;
}
