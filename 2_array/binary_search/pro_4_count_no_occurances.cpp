#include <bits/stdc++.h>
using namespace std;
int countFirstOccurance(int arr[], int n, int ele)
{
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > ele)
            high = mid - 1;
        else if (arr[mid] < ele)
            low = mid + 1;
        else if (arr[mid] == ele)
        {
            if (mid == 0 || arr[mid] != arr[mid - 1])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int countLastOccuracne(int arr[], int n, int ele)
{
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > ele)
            high = mid - 1;
        else if (arr[mid] < ele)
            low = mid + 1;
        else if (arr[mid] == ele)
        {
            if (mid == n - 1 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}
// this is O(logn) solution
int countOccurance(int arr[], int n, int ele)
{
    int firstOcc = countFirstOccurance(arr, n, ele);
    if (firstOcc == -1)
        return 0;
    return countLastOccuracne(arr, n, ele) - firstOcc + 1;
}
int main()
{
    int arr[] = {5, 10, 10, 10, 10, 20, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ele;
    cin >> ele;
    cout << countOccurance(arr, n, ele);
    return 0;
}