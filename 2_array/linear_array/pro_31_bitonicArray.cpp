#include <bits/stdc++.h>
using namespace std;
int findMaximum(int arr[], int n)
{
    // code here
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        bool cond1 = arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1];
        if (cond1 || mid == 0 || mid == n - 1)
            return arr[mid];

        else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
            high = mid - 1;
        else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 15, 25, 45, 42, 21, 17, 12, 11};
}