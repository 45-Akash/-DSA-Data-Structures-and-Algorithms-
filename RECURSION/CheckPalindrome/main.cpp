#include <iostream>

using namespace std;

bool checkPalindrome(string str, int s, int e)
{
    if(s>e)       return true;

    if(str[s]!=str[e]) return false;
    return checkPalindrome(str, s+1, e-1);
}
int main()
{
    string str;
    cin>>str;
    int n=str.length();

    if(checkPalindrome(str,0,n-1))
    {
        cout<<"The given string is palindrome"<<endl;
    }
    else
    {
        cout<<"The given string is not a palindrome"<<endl;
    }
    return 0;
}
