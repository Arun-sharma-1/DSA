//NOT WORKING 
#include <bits/stdc++.h>
using namespace std;
 
int maxsum_subarray(int arr[], int n)
{
    int result = arr[0];
    int maxending=arr[0];
    for(int i=0; i<n; i++)
    {
        maxending=max(maxending+arr[i],arr[i]);
        result=max(result,maxending);
    }
    return result;
 
}
int main()
{
    int arr[] = {1, 2, 3, -3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxsum_subarray(arr, n);
}