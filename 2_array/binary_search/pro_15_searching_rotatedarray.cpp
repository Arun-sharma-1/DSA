#include <bits/stdc++.h>
using namespace std;

// array is rotated sorted  = > element will be present on left side of mid or either right side of mid ,
// we will confirm by this comparing with the mid with corner element

// accepted on gfg
int search(int arr[], int start, int end, int ele)
{
    // l: The starting index
    // h: The ending index, you have to search the key in this range
    while (end >= start)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele)
            return mid;

        // 2 case will be there
        // 1.either left half is sorted
        // 2.right half will be sorted

        else if (arr[mid] >= arr[start])
        {
            // left half sorted mil gya

            if (ele >= arr[start] && arr[mid] >= ele)
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            // right half sorted h
            if (arr[end] >= ele && arr[mid] <= ele)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {10, 20, 40, 60, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ele;
    cin >> ele;
    cout << search(arr, n, ele);
    return 0;
}