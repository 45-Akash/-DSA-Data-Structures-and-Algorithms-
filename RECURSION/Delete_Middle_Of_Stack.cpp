
#include <bits/stdc++.h>

using namespace std;

void solve(stack<int>&s, int k)
{
    if(k==1)    
    {
        s.pop();
        return;
    }
    
    int temp = s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);
}

void delMid(stack<int>&s, int size)
{
    if(size==0)   return;
    
    int k = (size/2) +1;
    
    solve(s,k);
}


int main()
{
    stack<int>st;
    int n;
    cout<<"Enter the stack size ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    
    delMid(st,n);
    
    while(st.size()!=0)
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}