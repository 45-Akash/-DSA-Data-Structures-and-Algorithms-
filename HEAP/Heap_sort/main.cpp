#include <bits/stdc++.h>

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


        // Heapify function
        void heapify(int arr[], int n, int i)
        {
            int largest=i;
            int right_child = 2*i+1;
            int left_child = 2*i;

            if(left_child <= n && arr[left_child] > arr[largest])
            {
                largest = left_child;
            }
            if(right_child <= n && arr[right_child] > arr[largest])
            {
                largest = right_child;
            }

            if(largest != i)
            {
                swap(arr[largest], arr[i]);
                heapify(arr, n, largest);
            }
        }


        // Building Max-Heap
        void Insert(int val)
        {
            Size++;
            arr[Size]=val;

            int current_index = Size;

            while(current_index > 1)
            {
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

        //Calling HeapSort
        void heapSort()
        {
            int S = Size;

            while(S > 1)
            {
                //step 1 :- swap first and last element
                swap(arr[1], arr[S]);
                S--;

                //heapify
                heapify(arr, S, 1);
            }
        }


        //Displaying Heap
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
    heap p;
    int choice;

    do{
        cout<<endl<<"\t1.Insert\t2.heapSort\t3.print \t4.Exit"<<endl;
        cout<<"\tEnter choice :- ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                int val;
                cout<<"\tEnter value to be inserted :- ";
                cin>>val;
                p.Insert(val);
                break;
            case 2:
                p.heapSort();
                break;
            case 3:
                p.Print();
                break;
            case 4:
                cout<<"\tEXIT"<<endl;

        }
    }while(choice!=4);

    return 0;
}
