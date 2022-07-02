#include <iostream>

using namespace std;

class heap{

    public:
        int arr[100];
        int Size;

    heap()
    {
        arr[0]=-1;
        Size=0;
    }

    void Insert(int val)
    {
        //increment array size by 1
        Size++;

        //place the value at end of array
        arr[Size]=val;
        int current_index = Size;


        while(current_index > 1)
        {
            //compare the current node value with its parent node value
            //if the current node value greater than parent node value
            //  then swap those value (apply this recursively to all node till index 1)
            //else the nodes are in position --> return
            int parent_index = current_index/2;
            if(arr[parent_index] < arr[current_index])
            {
                swap(arr[parent_index], arr[current_index]);
                current_index = parent_index;
            }
            else
            {
                return;
            }
        }
    }

    void Delete()
    {
        if(Size==0)
        {
            cout<<"\tNo Element to delete "<<endl;
            return;
        }
        //In delete operation we delete root node value
        //Maximum value in case of Max_Heap

        //assign last node value to root node and decrease size by 1
        arr[1] = arr[Size];
        Size--;

        int current_index=1;
        int left_child_index,Right_child_index;

        while(current_index < Size)
        {
            left_child_index = current_index*2;
            Right_child_index = left_child_index+1;


            if(left_child_index < Size && arr[current_index] < arr[left_child_index])
            {

                swap(arr[current_index], arr[left_child_index]);
                current_index = left_child_index;
            }
            else if(Right_child_index < Size && arr[current_index] < arr[Right_child_index])
            {

                swap(arr[current_index], arr[Right_child_index]);
                current_index = Right_child_index;
            }
            else
            {
                return;
            }
        }
    }
    void Print()
    {
        for(int i=1; i<=Size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

int main()
{
    heap h;

    int choice;

    do{
        cout<<endl<<"\t1.Insert\t2.Delete\t3.Display\t4.Exit"<<endl;
        cout<<"\tEnter choice :- ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                int val;
                cout<<"\t\tEnter value :- ";
                cin>>val;
                h.Insert(val);
                break;
            case 2:
                h.Delete();
                break;
            case 3:
                h.Print();
                break;
            case 4:
                cout<<"-------------------------Exit----------------------------"<<endl;

        }
    }while(choice!=4);


    // TC for Insertion = O(log n)
    // TC for Deletion = O(log n)

    return 0;
}
