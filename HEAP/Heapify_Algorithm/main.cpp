#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest=i;
    int right_child = 2*i+1;
    int left_child = 2*i;

    if(left_child < n && arr[left_child] > arr[largest])
    {
        largest = left_child;
    }
    if(right_child < n && arr[right_child] > arr[largest])
    {
        largest = right_child;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    cout << "\tHeapify is the process of reshaping binary tree into heap data structure"<<endl;
    int n=6;
    int arr[n] = {-1, 50, 55, 43, 45, 78,89};

    //apply heapify on all non leaf nodes
    for(int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }

    //print tree
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
