// maximum value of arr[i]-arr[j] such that j>i
#include <bits/stdc++.h>
using namespace std;
int max_value(int arr[], int n)
{
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] > diff)
            {
                diff = arr[j] - arr[i];
            }
        }
    }
    return diff;
}
int maxi_value(int arr[], int n)
{
    // the idea is to keep track of minimum and maximum value 
    int result = arr[1] - arr[0];
    int min_val = arr[0];
    for (int i = 0; i < n; i++)
    {
        result = max(result, arr[i] - min_val);
        min_val = min(min_val, arr[i]);
    }
    return result;
}

int main()
{
    int arr[] = {10, 20, 30};
    cout << maxi_value(arr, 3);
}