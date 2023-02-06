#include <bits/stdc++.h>
using namespace std;
vector<int> getLeftMax(vector<int> &height, int n)
{
    vector<int> ans(n, 0);
    ans[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        ans[i] = max(height[i], ans[i - 1]);
    }
    return ans;
}
vector<int> getRightMax(vector<int> &height, int n)
{
    vector<int> ans(n, 0);
    ans[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(height[i], ans[i + 1]);
    }
    return ans;
}
int trap(vector<int> &height)
{
    int n = height.size();
    int res = 0;
    vector<int> leftMax = getLeftMax(height, n);
    vector<int> rightMax = getRightMax(height, n);
    for (int i = 0; i < n; i++)
    {
        int h = min(leftMax[i], rightMax[i]) - height[i];
        res += h;
    }
    return res;
}
int main()
{
    int arr[] = {3, 0, 1, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << getWater(arr, size);
}