#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array :- ";
    cin>>n;

    vector<int>vec(n,0);
    cout<<"Enter the vector elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }

    int Xor = 0;
    for(int i=0; i<n; i++)      Xor^=vec[i];

    cout<<"The single element is :- "<<Xor<<endl;
    return 0;
}
