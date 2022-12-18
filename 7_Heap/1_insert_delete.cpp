#include <bits/stdc++.h>
using namespace std;
class Heap
{
    int arr[100];
    int size;

public:
    Heap()
    {
        size = 0;
    }
    // max heap
    void insert(int ele)
    {
        int index = size;
        size++;
        arr[index] = ele;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[index] > arr[parent])
            {
                // writing ele at the place of arr[index] will creat4 issue
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
                return;
        }
    }
    void delEle()
    {
        swap(arr[0], arr[size - 1]);
        int i = 0;
        size--;
        while (i < size)
        {
            int l = 2 * i + 1;
            int r = l + 1;

            if (l < size && arr[i] < arr[l])
            {
                swap(arr[i], arr[l]);
                i = l;
            }
            else if (r < size && arr[i] < arr[r])
            {
                swap(arr[i], arr[r]);
                i = r;
            }
            else
                return;
        }
    }
    int findEle(int ele)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == ele)
                return i;
        }
        return -1;
    }
    int left(int ele)
    {
        int index = findEle(ele);
        return arr[2 * index + 1];
    }
    int right(int ele)
    {
        int index = findEle(ele);
        return arr[2 * index + 2];
    }
    void printEle()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

};
int main()
{
    vector<int> arr = {10, 20, 40, 30, 80, 60, 50};
    buildheap(arr, arr.size() - 1);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}