#include <bits/stdc++.h>
using namespace std;
//same as finding minimun element
int SortedArray(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    if(arr[high] >= arr[low]) return 0;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] <= arr[next] && arr[prev] >= arr[mid])
        {   
            return arr[mid]; // means it is the smallest so it should come low and index of this value is answer
        }
        //THESE BOTH CONDITION will throw to unordered part of array coz in unordered we will get the smallest 
        if (arr[mid] >= arr[low])
            low = mid + 1;
        else if (arr[mid] <= arr[high])
            high  = mid - 1;
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