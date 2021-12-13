#include <bits/stdc++.h>
using namespace std;
int left_rotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i - 1] = arr[i];
            // arr[i]=arr[i+1];       first we will get garbage value so don't use arr[i+1] istead start arr form 1 and use arr[i-1]

            arr[n - 1] = temp;
}
// left rotate by d
int approach_1st(int arr[] , int n , int d)
{
    int temp[n];
    for(int i=0; i<d; i++)
        temp[i]=arr[i];
    for(int i=d; i<n; i++)
        arr[i-d]=arr[i];
    for(int i=0; i<d; i++)
        arr[n-d+i]=temp[i];
    
}
int main()
{
    int arr[] = {11, 12, 3, 42};
    int n = sizeof(arr) / sizeof(arr[0]);

    // left_rotate(arr, n);\
    
    approach_1st(arr,n,2);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}