#include <bits/stdc++.h>
using namespace std;
void rainWater(int arr[], int n)
{
    int left[n], right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int water[n];

    for (int i = 0; i < n; i++)
    {
        water[i] = min(left[i], right[i]) - arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += water[i];
    }
    cout << sum;
}
int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    rainWater(arr, n);
    return 0;
}