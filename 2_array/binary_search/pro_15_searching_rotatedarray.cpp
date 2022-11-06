#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int ele)
{
    // array is rotated sorted  = > element will be present on left side of mid or either right side of mid ,
    // we will confirm by this comparing with the mid with corner element
    int low = 0;
    int high = n - 1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == ele)
            return mid;
        if (arr[low] < arr[mid])
        {
            // left half is sorted
            if (ele >= arr[low] && arr[mid] > ele)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            // right half sorted
            if (ele <= arr[high] && ele > arr[mid] )
                low = mid + 1;
            else
                high = mid - 1;
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