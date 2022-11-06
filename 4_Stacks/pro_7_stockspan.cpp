#include <bits/stdc++.h>
using namespace std;
void stockSpan(int arr[], int n)
{
    vector<int> v;
    // stack<int>s;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > arr[i])
        {
            v.push_back(s.top().second); // index push kiya
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && arr[i] >= s.top().first)
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                // if size become 0
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = i - v[i];
    }

    for (auto ele : v)
    {
        cout << ele << ",";
    }
}
int main()
{
    // int arr[] = {100, 80, 60, 70, 60, 75, 85};
    // int arr[] = {1, 0, 2, 1, 4};
    int arr[] = {2, 1, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    stockSpan(arr, n);
    return 0;
}