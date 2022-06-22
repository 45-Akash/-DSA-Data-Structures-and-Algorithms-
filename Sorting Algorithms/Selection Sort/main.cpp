#include <bits/stdc++.h>

using namespace std;

void SelectionSort(vector<int>&vec, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int Min=i;
        for(int j=i+1; j<n; j++)
        {
            if(vec[j]<vec[Min])    Min=j;
        }
        swap(vec[Min],vec[i]);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of Array :- ";
    cin>>n;
    vector<int>arr(n,0);

    for(int i=0; i<n; i++)     cin>>arr[i];

    SelectionSort(arr,n);
    for(auto it:arr)           cout<<it<<" ";
    return 0;
}
