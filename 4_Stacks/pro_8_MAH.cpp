#include <bits/stdc++.h>
using namespace std;
// NSR
vector<int> NSR(int arr[], int n)
{
    stack<pair<int, int>> s;
    vector<int> right;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            right.push_back(n); // inserting index of last element to make last element less
        }
        else if (s.size() > 0 && arr[i] >= s.top().first)
        {
            right.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                right.push_back(n);
            }
            else
            {
                right.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    return right;
}
// NSL
int NSL(int arr[], int n)
{
    stack<pair<int, int>> s;
    vector<int> left;
    vector<int> right = NSR(arr, n);
    vector<int> width(n);
    vector<int> area(n);

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            left.push_back(-1);
        }
        else if (s.size() > 0 && arr[i] > s.top().first)
        {
            left.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        area[i] = arr[i] * width[i];
    }

    int max = -1;
    for (int i = 0; i < area.size(); i++)
    {
        if (area[i] > max)
        {
            max = area[i];
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<area[i]<<",";
    }
    cout<<endl;
    return max;
}
int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << NSL(arr, n);
    return 0;
}