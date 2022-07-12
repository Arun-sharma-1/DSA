#include <bits/stdc++.h>
using namespace std;
int maxEvenOddSubarray(int arr[], int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
                curr++;
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}
int app_2nd(int arr[], int n)
{
    // apprach of kandens algorithm
    int res = 1;
    int curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] % 2 == 0 && arr[i] % 2 != 0 || arr[i - 1] % 2 != 0 && arr[i] % 2 == 0)
        {
            curr++;
            res = max(res, curr);
        }
        else
            curr = 1;
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << app_2nd(arr, size);
}