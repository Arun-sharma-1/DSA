#include <bits/stdc++.h>
using namespace std;
int infiniteSortedArr(int arr[], int n, int ele)
{
    // in case of infinite array we move slowely toward element
    int start = 0;
    int end = 1;
    while (ele > arr[end])
    {
        start = end;
        end *= 2;
    }
    // here we got the element between low and high

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // to handle overflow condition

        if (arr[mid] == ele)
            return mid;

        else if (arr[mid] > ele)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << infiniteSortedArr(arr, n, 10);
    return 0;
}