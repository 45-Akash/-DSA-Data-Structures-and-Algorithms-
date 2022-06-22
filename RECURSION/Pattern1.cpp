#include <iostream>

using namespace std;

void patternPrint(int n)
{
    if(n==1) 
    {
        cout<<"1"<<endl;
        return;
    }
    
    for(int i=n; i>0; i--)
    {
        cout<<i<<" ";
    }
    
    cout<<endl;
    patternPrint(n-1);
    
    for(int i=n; i>0; i--)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    
}

int main()
{
   patternPrint(5);
    return 0;
}