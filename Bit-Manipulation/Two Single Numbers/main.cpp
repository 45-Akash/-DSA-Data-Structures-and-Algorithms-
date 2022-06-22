#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter size of vector :- ";
    cin>>n;

    vector<int>vec(n,0);
    cout<<"Enter vector elements :-"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }

    //find xor of all elements
    int Xor=0;
    for(auto it:vec)      Xor= Xor ^ it;

    //find the index of first set bit
    int fst=(Xor &~(Xor-1))-1;        //firstSetBit

    /*while(Xor)
    {
        if(Xor&1==1)
            break;
        fst++;
        Xor = Xor >> 1;
    }*/

    //Find the two numbers
    int xor_1=0, xor_2=0;
    for(int i=0; i<n; i++)
    {
        if((vec[i]&(1<<fst)) !=0)            //fst th bit is set
        {
            xor_1 = xor_1^vec[i];
        }
        else                                //fst the bit is not set
        {
            xor_2^=vec[i];
        }
    }

    cout<<"The two common numbers are "<<xor_1<<" and "<<xor_2<<endl;


    return 0;
}
