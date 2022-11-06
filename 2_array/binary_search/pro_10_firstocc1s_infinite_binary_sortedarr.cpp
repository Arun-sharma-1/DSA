#include <bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int n)
{
    int low = 0;
    int res = 0;
    int high = 1;
    int ele=1;
    while (1 > arr[high])
    {
        low = high;
        high *= 2;
    }
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (ele > arr[mid])
            low = mid + 1;
        else if (ele < arr[mid])
            high = mid - 1;
        else
        {
            if (arr[mid] != arr[mid - 1] || mid == 0)
                return mid;
            else
                high = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<firstOcc(arr,n);
    return 0;
}