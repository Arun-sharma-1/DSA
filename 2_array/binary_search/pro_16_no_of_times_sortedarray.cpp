#include <bits/stdc++.h>
using namespace std;
int SortedArray(int arr[], int n)
{
    int first = 0;
    int last = n - 1;
    while (last >= first)
    {
        int mid = first + (last - first) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] <= arr[next] && arr[prev] >= arr[mid])
        {
            return arr[mid]; // means it is the smallest so it should come first and index of this value is answer
        }
        //THESE BOTH CONDITION will throw to unordered part of array coz in unordered we will get the smallest 
        else if (arr[mid] >= arr[first])
            first = mid + 1;
        else if (arr[mid] <= arr[last])
            last = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << SortedArray(arr, n);
    return 0;
}