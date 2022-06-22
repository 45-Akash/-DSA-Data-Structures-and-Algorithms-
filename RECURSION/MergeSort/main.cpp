#include <bits/stdc++.h>

using namespace std;

void mergeTwoSortedArray(vector<int>left,vector<int>right, int len1, int len2, vector<int>&arr, int s)
{
    int index1=0;
    int index2=0;
    int ind=s;

    while(index1<len1 && index2<len2)
    {
        if(left[index1]<right[index2])
        {
            arr[ind++]=left[index1++];
        }
        else
        {
            arr[ind++]=right[index2++];
        }
    }

    while(index1<len1)
    {
        arr[ind++]=left[index1++];
    }

    while(index2<len2)
    {
        arr[ind++]=right[index2++];
    }
}

void Merge(vector<int>&arr, int s, int e)
{
    int mid = s + (e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    //make left and right sorted arrays
    vector<int>left(len1);
    vector<int>right(len2);

    int startIndex = s;
    for(int i=0; i<len1; i++)
    {
        left[i] = arr[startIndex++];
    }

    startIndex = mid+1;
    for(int i=0; i<len2; i++)
    {
        right[i] = arr[startIndex++];
    }

    //merge two sorted arrays
    mergeTwoSortedArray(left,right,len1,len2,arr,s);
}

void mergeSort(vector<int>&arr, int s, int e)
{
    if(s>=e)     return;

    int mid = s + (e-s)/2;

    //call mergeSort function for left part array
    mergeSort(arr, s, mid);

    //call mergeSort function for right part array
    mergeSort(arr, mid+1, e);

    //call merge function
    Merge(arr, s, e);
}
int main()
{
    int n;
    cin>>n;

    vector<int>vec(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }

    //call sorting function
    mergeSort(vec, 0, n-1);

    for(int i=0; i<n; i++)    cout<<vec[i]<<" ";
    return 0;
}
