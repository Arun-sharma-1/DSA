#include <bits/stdc++.h>
using namespace std;
// using Two pointer approach
// not working
bool isPrefixSum(int arr[], int n, int sum)
{
    int left = 0, right = 0;
    int res = 0;
    while (left <= right)
    {
        if (res == sum)
            return true;
        if (res < sum && right != n - 1)
        {
            res += arr[right];
            cout << "if " << res << endl;
        }
        else
        {
            res -= arr[left];
            cout << "else " << res << endl;
            left++;
        }
        right++;
    }
    return false;
}
bool isSum(int arr[], int n, int sum)
{
    unordered_set<int> uset;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum)
            return true;
        if (uset.find(prefixSum - sum) != uset.end())
            return true;
        uset.insert(prefixSum);
    }
    return false;
}
int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSum(arr, n,24);
    return 0;
}