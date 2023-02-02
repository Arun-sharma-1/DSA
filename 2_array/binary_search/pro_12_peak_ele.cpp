#include <bits/stdc++.h>
using namespace std;
/*
    this problem can also be converted to finding maximum in biotonic array
    bitonic array means, it is increasing at one time and go to its peak and then decreasing
    so we have to find the maximum in that and the peak element will be maximum
*/
//->aditya verma
int peakElement(int arr[], int n)
{
    // if the element is greater from its left side element and right side element then it is a peak element
    // for the first ele is should compare to only one 2nd ele
    // for the last ele is should compare to only 2nd last ele
    // this problem is also considered as binary search on answers and we are applying binary search here in unsorted array

    int start = 0;
    int end = n - 1;
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid - 1] > arr[mid])
            {
                // moving  to that side which have higher chances to get the peak element
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
                return 0;
            return 1;
        }
        if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 2])
                return n - 1;
            return n - 2;
        }
    }
    return -1;
}
// ACCEPTED ON GFG 
int peakelement(int arr[], int n)
{
    // Your code here
    int start = 0;
    int end = n - 1;
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
                return mid;
            else if (arr[mid - 1] > arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        if (mid == 0)
        {
            if (arr[0] > arr[1])
                return 0;
            else
                start = mid + 1;
        }
        if (mid == n - 1)
        {
            if (arr[mid] > arr[n - 2])
                return n - 1;
            end = mid - 1;
        }
    }
}
int main()
{
    int arr[] = {2, 10, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << peakElement(arr, n);
    return 0;
}