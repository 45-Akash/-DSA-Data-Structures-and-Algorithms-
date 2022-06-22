#include <bits/stdc++.h>

using namespace std;

void InsertionSort(vector<int>&vec, int n)
{
    for(int i=1; i<n; i++)
    {
        int temp = vec[i];
        int j = i-1;
        while(j>=0 && vec[j]>temp)
        {
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=temp;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of Array :- ";
    cin>>n;
    vector<int>arr(n,0);

    for(int i=0; i<n; i++)     cin>>arr[i];

    InsertionSort(arr,n);
    for(auto it:arr)           cout<<it<<" ";

    return 0;
}
