#include <bits/stdc++.h>
using namespace std;
//heap sort usses max Heapfiy , complexity is nlogn
//babbar
void maxHeapify(vector<int>&arr , int i , int size)
{
    int l = 2 * i + 1;
    int r = l + 1;
    int largest = i;
    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) // means the data has changed
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr ,largest , size);
    }
}
void bulidHeap(vector<int>&arr,int size)
{
    for(int i=size/2; i>=0; i--)
    {
        maxHeapify(arr,i,size);
    }
}
void Heap_sort(vector<int> &arr, int size)
{
    int i = size-1;
    for(int i=size/2-1; i>=0; i--)
        maxHeapify(arr,i,size);
    
    while(i > 0)
    {
        //step 1
        swap(arr[i], arr[0]);
        i--;

        //step 2;
        maxHeapify(arr, 0 , i); // size of elemennt is reducing in each step so size is i
        //passing size is important in maxHeapify and maxheapify should take size as a argument also
    }
     
}
int main()
{
    vector<int> arr = {80,50,60,70};
    Heap_sort(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}