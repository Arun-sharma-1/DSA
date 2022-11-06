#include <bits/stdc++.h>
using namespace std;
int result;
int merge1(vector<int> &arr, int a, int b, int m)
{
    vector<int> arr1(arr.begin() + a, arr.begin() + m + 1);
    vector<int> arr2(arr.begin() + m + 1, arr.begin() + b + 1);
    int i = 0, j = 0, k = a;
    int ans = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] > arr2[j])
        {
            arr[k++] = arr2[j++];
            ans += m - i + 1;
        }
        else if (arr1[i] <= arr2[j])
        {
            arr[k++] = arr1[i++];
        }
    }
    while (i < arr1.size())
    {

        arr[k++] = arr1[i++];
    }
    while (j < arr2.size())
    {
        arr[k++] = arr2[j++];
    }
    return ans;
}
int merge_sort(vector<int> &arr, int a, int b)
{
    // base conditon
    if (a >= b)
        return 0;
    int mid = a + (b - a) / 2;
    int left = merge_sort(arr, a, mid);
    int right = merge_sort(arr, mid + 1, b);

    int common = merge1(arr, a, b, mid);
    return left + right + common;
}

int main()
{

    vector<int> arr = {2, 4, 1, 3, 5};
    cout<<merge_sort(arr, 0, arr.size() - 1);
    // for (auto ele : arr)
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;
    // cout << "answer is " << result << endl;
    return 0;
}