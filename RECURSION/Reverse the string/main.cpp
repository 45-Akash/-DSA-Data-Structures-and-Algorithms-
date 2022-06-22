#include <bits/stdc++.h>

using namespace std;

void Reverse(string &str , int s, int e)
{
    if(s>=e)    return;

    swap(str[s],str[e]);
    Reverse(str, s+1, e-1);
    return;
}
int main()
{

    string str;
    cin>>str;
    int n=str.length();

    cout<<"String before reversing = "<<str<<endl;
    Reverse(str,0,n-1);
    cout<<"String After reversing = "<<str<<endl;
    return 0;
}
