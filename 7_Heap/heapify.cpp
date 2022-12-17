#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int index, int size)
{
    int left, right, max;
    left = 2 * index + 1;
    right = left + 1;
    max = index;

    if (left <= size && arr[left] > arr[max])
        max = left;
    if (right <= size && arr[right] > arr[max])
        max = right;

    if (index != max)
    {
        swap(arr[max], arr[index]);
        heapify(arr, max, size);
    }
}
void buildheap(vector<int> &arr, int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        heapify(arr, i, size);
    }
}

int main()
{
    vector<int> arr = {10, 20, 40, 30, 80, 60, 50};
    buildheap(arr, arr.size() - 1);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}