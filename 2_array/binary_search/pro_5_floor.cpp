#include <bits/stdc++.h>
using namespace std;
int floor(int arr[], int n, int ele)
{
    int res = 0;
    int start = 0;
    int end = n - 1;
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
            return arr[mid];
        
        //if element is greater then current element in array then only it can be candidate for floor 
        if (arr[mid] < ele)
        {
            start = mid + 1;
            // if (arr[mid] < ele)
                res = arr[mid];
        }
        else
        {
            end = mid - 1
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << floor(arr, n, 5);
    return 0;
}