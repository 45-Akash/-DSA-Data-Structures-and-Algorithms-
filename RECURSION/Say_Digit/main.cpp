#include <bits/stdc++.h>

using namespace std;


void sayDigit(int digit, unordered_map<int,string>&mp)
{
    if(digit<=0)
        return;
    sayDigit(digit/10, mp);
    cout<<mp[digit%10]<<" ";
}


int main()
{
    int digit;
    cin>>digit;

    unordered_map<int,string>mp;
    mp[0]="Zero";
    mp[1]="One";
    mp[2]="Two";
    mp[3]="Three";
    mp[4]="Four";
    mp[5]="Five";
    mp[6]="Six";
    mp[7]="Seven";
    mp[8]="Eight";
    mp[9]="Nine";

    sayDigit(digit,mp);
    return 0;
}
