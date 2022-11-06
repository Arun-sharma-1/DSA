#include <bits/stdc++.h>
using namespace std;

int approach_1st(int arr[], int n)
{
    int temp[n];
    int res = 1;
    temp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != temp[res - 1])
        {
            temp[res] = arr[i];
            res++;
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    return res;
}

int approach_2nd(int arr[] , int n)
{
    int res=1;
    for(int i=1; i<n; i++)
    {
        if(arr[i]!=arr[res-1])
        {
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 2, 3, 3, 4, 4, 9, 8, 9};

    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    n = approach_2nd(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}