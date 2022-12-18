#include <bits/stdc++.h>
using namespace std;
// this heapify function set the value at its correct position and when it is called for n/2 elements then all the values 
// are positioned at the right position
void minHeapify(int arr[] , int i , int size)
{
    int l = 2 * i + 1;
    int r = l + 1;
    int smallest = i;
    if (l < size && arr[l] < arr[i])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i) // means the data has changed
    {
        swap(arr[i], arr[smallest]);
        minHeapify(smallest);
    }
}
// this function will rearrange all the nodes at right position
/*
This buildHeap is required because --
    Leaf nodes are present in complete BT from n/2 ---> n/2-1 and leaf nodes are already arranged 
    so we don't have to check them in heapify 
    so we traverse the loop from n/2  to 0 =>love babbar
*/
void buildheap(int arr[] , int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        minHeapify(arr , i , size);
    }
}
int main()
{
    return 0;
}