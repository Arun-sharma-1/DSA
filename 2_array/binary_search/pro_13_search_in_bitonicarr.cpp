#include <bits/stdc++.h>
using namespace std;
// NOT WORKING
int findPeakIndex(vector<int> &arr, int n)
{
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (mid == 0)
        {
            if (arr[0] > arr[1])
                return 0;
            else
                low = mid + 1;
        }
        if (mid == n - 1)
        {
            if (arr[mid] > arr[n - 2])
                return n - 1;
            high = mid - 1;
        }

        else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid - 1] > arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
int binarySearch(vector<int> &arr, int n, int ele, int low, int high)
{
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == ele)
            return mid;
        else if (arr[mid] < ele)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int solve(vector<int> &arr, int ele)
{
    // find peak element index and apply search on both sides
    int n = arr.size();
    int peakIndex = findPeakIndex(arr, n);

    int firstHalf = binarySearch(arr, n, ele, 0, peakIndex - 1);
    int secondHalf = binarySearch(arr, n, ele, peakIndex, n - 1);
    return max(firstHalf, secondHalf);
}
int main()
{
    return 0;
}