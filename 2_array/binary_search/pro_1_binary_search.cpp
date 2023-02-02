#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int n, int ele)
{
    int start = 0, end = n - 1;
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
int RecursiveBinarySearch(int arr[], int n, int ele, int start, int end)
{
    int mid = start + (end - start) / 2;
    // base condn
    if (arr[mid] == ele)
        return mid;
    if (start > end)
        return -1;
    if (arr[mid] > ele)
         RecursiveBinarySearch(arr, n, ele, start, mid-1);
     
    else
        RecursiveBinarySearch(arr, n, ele, mid + 1, end);
}
int main()
{
    int arr[] = {10, 10 ,20 , 30,40,45,60};
    int no;
    cin >> no;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << RecursiveBinarySearch(arr, n, no , 0 ,n-1);
    return 0;
}