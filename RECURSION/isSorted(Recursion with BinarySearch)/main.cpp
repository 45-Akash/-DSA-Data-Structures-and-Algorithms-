#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int>&v, int s, int e, int n)
{
    if(s==e)    return true;

    int m = s + (e-s)/2;
    if(m==0)
    {
        if(v[0]>v[1])
        {
            return false;
        }
    }
    else if(m==n-1)
    {
        if(v[n-1]<v[n-2])
        {
            return false;
        }
    }
    else if(v[m]<v[m-1] || v[m]>v[m+1])
    {
        return false;
    }

    return isSorted(v, s, m, n) && isSorted(v, m, e, n);

}
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n,0);

    for(int i=0; i<n; i++)   cin>>vec[i];

    if(isSorted(vec,0,n-1,n))
    {
        cout<<"Array is Sorted"<<endl;
    }
    else
    {
        cout<<"Array is not Sorted"<<endl;
    }
    return 0;
}
