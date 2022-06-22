<------------------------------Modifies Input--------------------------->
#include <iostream>

using namespace std;

void Subset(string In, string op)
{
    if(In.size()==0)
    {
        cout<<op<<endl;
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    op2.push_back(In[0]);
    In.erase(In.begin()+0);
    
    Subset(In, op1);
    Subset(In, op2);
}

int main()
{
    cout<<"Enter Input String :- ";
    string str;
    cin>>str;
    
    string out ="";
    
    Subset(str, out);

    return 0;
}


<--------------------------without modyfying input---------------->

#include <iostream>

using namespace std;

void Subset(string In, string op, int index)
{
    if(In.size()==index)
    {
        cout<<op<<endl;
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    op2 += In[index];
    
    Subset(In, op1,index+1);
    Subset(In, op2, index+1);
}

int main()
{
    cout<<"Enter Input String :- ";
    string str;
    cin>>str;
    
    string out ="";
    
    Subset(str, out, 0);

    return 0;
}