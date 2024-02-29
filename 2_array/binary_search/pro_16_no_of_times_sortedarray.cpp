#include <bits/stdc++.h>
using namespace std;
// same as finding minimun element
// jo mimimum element ka index h , utni baar array rotated h

int findMin(int arr[], int n)
{
    // same as no of time array is sorted

    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return arr[mid];

        // unsorted array m ans milega
        // we will move to unordered part by comparing mid with low and high index , minm ele will be present in unordrered side
        else if (arr[high] >= arr[mid])
            high = mid - 1;
        else if (arr[low] <= arr[mid])
            low = mid + 1;
    }
    return -1;
}
s int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << SortedArray(arr, n);
    return 0;
}