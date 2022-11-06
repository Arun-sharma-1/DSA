//NOT WORKING 
#include <bits/stdc++.h>
using namespace std;
int subArray(int arr[], int n)
{
    int result = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            result = max(result, curr);
        }
    }
    return result;
}
int MaxSubArray(int arr[], int n)
{
    int res =arr[0];
    int maxEnding = arr[0];
    for(int i=1; i<n; i++)
    {
        maxEnding = max(maxEnding + arr[i] , arr[i]);
        res = max(res , maxEnding);
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, -3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaxSubArray(arr, n);
}