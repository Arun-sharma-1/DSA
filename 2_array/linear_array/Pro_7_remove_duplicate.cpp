#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    int a = 0;
    //[1,2,3,3,4,4,5 ] ->
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != nums[a])
        {
            a++;
            nums[a] = nums[i];
        }
    }
    return a + 1;
}
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

int approach_2nd(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[res++] = arr[i];
        }
        arr[res++] = arr[n - 1];
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