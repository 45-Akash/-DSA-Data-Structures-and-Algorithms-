#include <bits/stdc++.h>

using namespace std;

int Partition(vector<int>&arr, int s, int e)
{
    //consider first as pivot element
    int pivot = arr[s];

    //count number of elements <= pivot
    int cnt=0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i]<=pivot)
            cnt++;
    }

    int pivotIndex = s+cnt;

    //place pivot at its correct position
    swap(arr[pivotIndex], arr[s]);

    int i=s, j=e;

    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot)  j--;

        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}
void QuickSort(vector<int>&arr, int s, int e)
{
    if(s>=e)    return;

    int p = Partition(arr, s, e);

    //left wala sort kro
    QuickSort(arr, s, p-1);

    //right wala sort karo
    QuickSort(arr, p+1, e);
}
int main()
{
    int n;
    cin>>n;

    vector<int>vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];

    QuickSort(vec, 0, n-1);

    //print array
    for(int i=0; i<n; i++) cout<<vec[i]<<" ";
    return 0;
}
